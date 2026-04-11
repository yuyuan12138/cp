/**
 *      author:  yuyuan567
 *      created: 2025-08-15 01:00:20
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

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    int mx = 0, mn = INT32_MAX;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        mx = std::max(mx, x);
        mn = std::min(mn, x);
    }
    
    std::vector<std::pair<int, int>> dp(n);
    debug(dp);
    
    std::cout << ((mx + mn) >> 1) << "\n";
    return 0;
}