#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using pii = pair<int, int>;

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
template<typename T>
T power_with_mod(T base, T exp, T mod) {
    if(exp == 0) return 1;
    if(exp == 1) return base;
    if(exp % 2){
        return (power_with_mod(base, exp / 2, mod) % mod) * (power_with_mod(base, exp / 2, mod) % mod) % mod * base % mod;
    }
    return (power_with_mod(base, exp / 2, mod) % mod) * (power_with_mod(base, exp / 2, mod) % mod) % mod;
}

template<typename T>
T power(T base, T exp) {
    if(exp == 0) return 1;
    if(exp == 1) return base;
    if(exp % 2){
        return (power(base, exp / 2)) * (power(base, exp / 2)) * base;
    }
    return (power(base, exp / 2)) * (power(base, exp / 2));
}

void solve(){
    ll n, q; cin >> n >> q;

    
    while(q--){
        string s; cin >> s;
        if (s == "->") {
            ll x, y;
            cin >> x >> y;
            cout << [](this auto&& self, ll x, ll y, ll min_v, ll max_v, ll size) -> ll {
                if(size == 1){
                    return min_v;
                }

                ll mid = size >> 1;
                ll diff = max_v - min_v + 1;
                if(x <= mid && y <= mid){
                    return self(x, y, min_v, max_v - diff / 4 * 3, mid);
                }
                if(x <= mid && y > mid){
                    return self(x, y - mid, max_v - diff / 4 + 1, max_v, mid);
                }

                if(x > mid && y <= mid){
                    return self(x - mid, y, max_v - diff / 2 + 1, max_v - diff / 4, mid);
                }

                if(x > mid && y > mid){
                    return self(x - mid, y - mid, max_v - diff / 4 * 3 + 1, max_v - diff / 2, mid);
                }

            }(x, y, 1LL, power(2LL, 2LL * n), power(2LL, n)) << "\n";
        }else{
            ll d; cin >> d;
            auto res = [](this auto&& self, ll x, ll y, ll min_v, ll max_v, ll size, ll d) -> pair<ll, ll> {
                if(size == 1){
                    return {x, y};
                }

                ll mid = size >> 1;
                ll diff = max_v - min_v + 1;
                if(d >= min_v && d <= max_v - diff / 4 * 3){
                    return self(x - mid, y - mid, min_v, max_v - diff / 4 * 3, mid, d);
                }
                if(d >= max_v - diff / 4 + 1 && d <= max_v){
                    return self(x - mid, y, max_v - diff / 4 + 1, max_v, mid, d);
                }

                if(d >= max_v - diff / 2 + 1 && d <= max_v - diff / 4){
                    return self(x, y - mid, max_v - diff / 2 + 1, max_v - diff / 4, mid, d);
                }

                if(d >= max_v - diff / 4 * 3 + 1 && d <= max_v - diff / 2){
                    return self(x, y, max_v - diff / 4 * 3 + 1, max_v - diff / 2, mid, d);
                }

            }(power(2LL, n), power(2LL, n), 1LL, power(2LL, 2LL * n), power(2LL, n), d);
            cout << res.first << " " << res.second << "\n";
        }
    }
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}