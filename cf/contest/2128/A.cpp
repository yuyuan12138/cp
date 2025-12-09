/**
 *      author:  yuyuan567
 *      created: 2025-07-27 22:36:09
 */
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;

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
    if(exp == 0) return 1LL;
    if(exp == 1) return base;
    if(exp % 2){
        return power(base, exp / 2) * power(base, exp / 2) * base;
    }
    return power(base, exp / 2) * power(base, exp / 2);
}

void solve(){
    ll n, c; cin >> n >> c;
    vector<ll> a(n + 1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(all(a));
    ll t = 0;
    ll cnt = 0;
    while(!a.empty()){
        int l = 0, r = a.size();
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(a[mid] <= c / power(2LL, t)){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        
        if(l != 0){
            a.erase(a.begin() + l - 1);
        }else{
            cnt++;
            a.pop_back();
        }
        t++;
    }
    cout << cnt << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}