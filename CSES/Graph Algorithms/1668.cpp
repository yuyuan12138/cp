#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<int> color(n, -1);
    auto dfs = [&](auto&& self, int u, int c) -> bool {
        if (color[u] != -1) {
            return true;
        }
        color[u] = c;
        for (int v : adj[u]) {
            if (color[v] == c) {
                return false;
            } else {
                if (!self(self, v, c ^ 1)) {
                    return false;
                }
            }
        }
        return true;
    };
    for (int u = 0; u < n; u++) {
        if (color[u] == -1) {
            if (!dfs(dfs, u, 0)) {
                std::cout << "IMPOSSIBLE";
                return 0;
            };
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << color[i] + 1 << " ";
    }
    return 0;
}
