/**
 *      author:  yuyuan567
 *      created: 2025-08-05 14:55:51
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
    int m, n;
    std::cin >> m >> n;
    std::vector<std::vector<int>> grids(m, std::vector<int>(n));
    bool has_1 = false;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> grids[i][j];
            if (grids[i][j])
                has_1 = true;
        }
    }
    std::vector<std::pair<int, int>> res;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grids[i][j] == 0)
                continue;
            bool flag1 = true;
            bool flag2 = true;
            for (int k = 0; k < n; k++) {
                if (grids[i][k] == 0) {
                    flag1 = false;
                }
            }
            for (int k = 0; k < m; k++) {
                if (grids[k][j] == 0) {
                    flag2 = false;
                }
            }
            if ((!flag1) && (!flag2)) {
                std::cout << "NO\n";
                return;
            }
            if (flag1 && flag2) {
                res.push_back({i, j});
            }
        }
    }

    std::vector<std::vector<int>> ans(m, std::vector<int>(n));
    if (res.empty() && has_1) {
        std::cout << "NO\n";
        return;
    }
    for (auto& [x, y] : res) {
        ans[x][y] = 1;
    }
    std::cout << "YES\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << ans[i][j] << " ";
        }
        std::cout << "\n";
    }

    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}