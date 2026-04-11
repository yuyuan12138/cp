#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            std::cin >> x;
            x--;
            adj[i].push_back(x);
        }
    }
    int ans = 0;
    std::vector<bool> vis(n);
    [&](this auto&& self, int u) -> void {
        if (vis[u]) {
            return;
        }
        ans++;
        vis[u] = true;
        for (int v : adj[u]) {
            self(v);
        }
    } (0);
    std::cout << ans;
    return 0;
}
