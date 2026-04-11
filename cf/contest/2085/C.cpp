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
        return power(base, exp / 2) * power(base, exp / 2) * base;
    }
    return power(base, exp / 2) * power(base, exp / 2);
}

void solve(){
    ll x, y; cin >> x >> y;
    if(x == y){
        cout << -1 << "\n";
    }else{
        cout << power(2LL, 48LL) - max(x, y) << "\n";
    }
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}