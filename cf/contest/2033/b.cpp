/**
 *      author:  yuyuan567
 *      created: 2025-08-27 19:47:37
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> grids(n, std::vector<int> (n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cin >> grids[i][j];
            }
        }
        debug(42);
        int ans = 0;
        for (int b = - (n - 1); b <= n - 1; b++) {
            int mn = 0;
            for (int x = 0; x < n; x++) {
                if (x + b < 0 || x + b > n - 1) continue;
                mn = std::min(mn, grids[x][x + b]); 
            }
            ans -= mn;
        }
        std::cout << ans << '\n';
        debug(ans);
    }
    return 0;
}
