/**
 *      author:  yuyuan567
 *      created: 2025-08-30 15:47:30
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
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj(n, std::vector<int>(n, INT32_MAX / 2));
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u][v] = adj[v][u] = 1;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adj[i][j] = std::min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (adj[i][n - 1] == INT32_MAX / 2) {
            std::cout << "-1 ";
        } else {
            std::cout << adj[i][n - 1] << " ";
        }
    }
    return 0;
}
