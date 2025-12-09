#include <bits/stdc++.h>

void solve() {
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
    [&](this auto&& self, int u, int c) -> void {
        if (color[u] != -1) {
            return;
        }
        color[u] = c;
        for (int v : adj[u]) {
            self(v, c ^ 1);
        }
    }(0, 0);
    int cnt = 0;
    for (int u = 0; u < n; u++) {
        if (color[u]) {
            cnt++;
        }
    }
    int flag;
    if (cnt <= n / 2) {
        flag = 1;
    } else {
        cnt = n - cnt;
        flag = 0;
    }
    std::cout << cnt << '\n';
    for (int u = 0; u < n; u++) {
        if (color[u] == flag) {
            std::cout << u + 1 << ' ';
        }
    }
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
