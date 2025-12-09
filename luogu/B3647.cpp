#include <bits/stdc++.h>

constexpr int inf = 1E9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> f(n, std::vector<int> (n, inf));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        f[u][v] = std::min(f[u][v], w);
        f[v][u] = std::min(f[v][u], w);
    }
    for (int i = 0; i < n; i++) {
        f[i][i] = 0;
    }


    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (f[i][k] != inf && f[k][j] != inf) {
                    f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << f[i][j] << " \n"[j == n - 1];
        }
    }

    return 0;
}
