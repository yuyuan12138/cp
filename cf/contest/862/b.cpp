#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<int> color(n, -1);
    [&](this auto&& self, int u, int pa, int c) -> void {
        color[u] = c;
        for (int v : adj[u]) {
            if (v != pa) {
                self(v, u, c ^ 1);
            }
        }
    }(0, -1, 0);
    int64_t cnt = 0;
    for (int i = 0; i < n; i++) {
        if (color[i]) {
            cnt++;
        }
    }
    std::cout << cnt * (int64_t(n) - cnt) - int64_t(n) + 1;
    return 0;
}
