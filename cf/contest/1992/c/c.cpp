/**
 *      author:  yuyuan567
 *      created: 2025-08-18 14:30:38
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n, m, k;
        std::cin >> n >> m >> k;
        std::vector<int> a(n);
        std::vector<int> ans;
        for (int i = n; i > m; i--) {
            ans.push_back(i);
        }
        for (int i = 1; i <= m; i++) {
            ans.push_back(i);
        }
        for (auto& x: ans) {
            std::cout << x << " ";
        }
        std::cout << '\n';
    }
    return 0;
}
