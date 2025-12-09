#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<int> size(n);
    i64 ans = 0;
    [&](this auto&& self, int u, int pa) -> void {
        size[u] = 1;
        for (int v : adj[u]) {
            if (pa != v) {
                self(v, u);
                size[u] += size[v];
                if (n - size[v] >= k) {
                    ans += size[v];
                }
            }
        }
        if (size[u] >= k) {
            ans += n - size[u];
        }
        ans++;
    } (0, -1);
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
