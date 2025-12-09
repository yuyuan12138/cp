/**
 *      author:  yuyuan567
 *      created: 2025-09-01 08:45:45
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
        int n, st, en;
        std::cin >> n >> st >> en;
        st--, en--;
        std::vector<std::vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            std::cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        std::vector<int> depth(n);
        [&](this auto&& self, int u, int pa, int dep) -> void {
            depth[u] = dep;
            for (int v : adj[u]) {
                if (v == pa) {
                    continue;
                }
                self(v, u, dep + 1);
            }
            return;
        }(en, -1, 0);
        std::vector<int> idx(n);
        std::iota(idx.begin(), idx.end(), 0);
        std::sort(idx.begin(), idx.end(), [&](int x, int y) -> bool {
            return (depth[x] == depth[y] ? x > y : depth[x] > depth[y]);
        });
        for (int i = 0; i < n; i++) {
            std::cout << idx[i] + 1 << " \n"[i == n - 1];
        }
    }
    return 0;
}
