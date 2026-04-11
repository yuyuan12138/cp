/**
 *      author:  yuyuan567
 *      created: 2025-08-15 16:12:58
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

    int tt;
    std::cin >> tt;
    while (tt--) {
        int n;
        std::cin >> n;
        std::vector<int> deg(n);
        std::map<std::pair<int, int>, bool> is_con;
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            std::cin >> u >> v;
            u--, v--;
            is_con[{u, v}] = is_con[{v, u}] = 1;
            deg[u]++;
            deg[v]++;
        }
        [&](this auto&& dfs, int u) -> void {

        }(0);
        std::vector<int> idx(n);
        std::iota(idx.begin(), idx.end(), 0);

        std::sort(idx.begin(), idx.end(), [&](int x, int y) -> bool {
            if (deg[x] == deg[y]) {
                return x < y;
            } else {
                return deg[x] > deg[y];
            }
        });        

        if (idx.size() >= 5) {
            idx.resize(5);
        }

        int ans = 0;
        
        for (int i = 0; i < idx.size(); i++) {
            for (int j = i + 1; j < n; j++) {
                if (is_con[{idx[i], idx[j]}]) {
                    ans = std::max(ans, deg[idx[i]] + deg[idx[j]] - 2);
                } else {
                    ans = std::max(ans, deg[idx[i]] + deg[idx[j]] - 1);
                }
            }
        }
        std::cout << ans << "\n";
        
        
        
    }

    return 0;
}