/**
 *      author:  yuyuan567
 *      created: 2025-08-10 23:26:47
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

void solve() {
    int n;
    std::cin >> n;
    if (n % 2 == 0) {
        for (int i = 0; i < n / 2 - 1; i++) {
            std::cout << "-1 3 ";
        }
        std::cout << "-1 2\n";
    } else {
        for (int i = 0; i < n / 2; i++) {
            std::cout << "-1 3 ";
        }
        std::cout << "-1\n";
    }
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}