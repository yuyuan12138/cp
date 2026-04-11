/**
 *      author:  yuyuan567
 *      created: 2025-08-12 23:43:33
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
    int a, b;
    std::cin >> a >> b;
    if (b % 2 == 0 && a % 2 == 0) {
        std::cout << "YES\n";
    } else {
        if (b % 2 == 1 && a % 2 == 0 && a >= 2) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return ;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1; std::cin >> t;
    while(t--) solve();
    return 0;
}