/**
 * @author: yuyuan567
 * @date: 2025-07-25 11:24:26
 */

#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../algo/debug.h"
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
    if(exp == 0) return 1;
    if(exp == 1) return base;
    if(exp % 2){
        return power(base, exp / 2) * power(base, exp / 2) * base;
    }
    return power(base, exp / 2) * power(base, exp / 2);
}

void solve(){
    int n, m; cin >> n >> m;
    vector<int> num_painters(m + 1);
    vector<ll> freq(n + 1);
    for(int i = 1; i <= m; i++){
        cin >> num_painters[i];
        freq[num_painters[i]]++;
    }
    // Colors: Colors[i] represents the number of colors that the number of it is greater than i.
    
    vector<ll> Colors(n + 2);

    for(int i = n; i >= 1; i--){
        Colors[i] = Colors[i + 1] + freq[i];
    }

    debug(Colors);
    ll tot = 0;
    for(int i = 1; i <= n - 1; i++){
        if(Colors[i] < 1 || Colors[n - i] < 1){
            continue;
        }
        tot += (Colors[i] * Colors[n - i] - min(Colors[i], Colors[n - i]));
    }
    cout << tot << "\n";

    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}