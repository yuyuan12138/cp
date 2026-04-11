/**
 *      author:  yuyuan567
 *      created: 2025-08-13 21:17:31
 */
#include <bits/stdc++.h>


#ifdef LOCAL
#include "../../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;

void solve(){
    int n;
    std::cin >> n;
    std::map<std::string, int> mp;
    
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        for (auto& c: s) {
            if (c == 'A' || c == '@') c = 'a';
            if (c == 'O' || c == '0') c = 'o';
            if ('A' <= c && c <= 'Z') {
                c = c - 'A' + 'a';
            }
        }
        mp[s]++;
    }
    ll ans = 0;
    for (auto [key, value]: mp) {
        ans += (ll) value * (value - 1) / 2;
    }
    std::cout << ans << "\n";
    return ;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    solve();
    return 0;
}