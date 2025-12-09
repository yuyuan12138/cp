#include <bits/stdc++.h>

void solve() {
    int n, d;
    std::cin >> n >> d;
    int s0, as, cs, rs;
    std::cin >> s0 >> as >> cs >> rs;
    int m0, am, cm, rm;
    std::cin >> m0 >> am >> cm >> rm;
    std::vector<std::vector<int>> adj(n);
    std::vector<int> s(n);
    s[0] = s0;
    for (int u = 1; u < n; u++) {
        m0 = (m0 * am + cm) % rm;
        s0 = (s0 * as + cs) % rs;
        adj[u].push_back(m0 % u);
        adj[m0 % u].push_back(u);
        s[u] = m0;
    }
    int ans = 0;
    
    auto dfs = [&](this auto&& self, int u, int pa) -> void {
        ans++;
        for (int v : adj[u]) {
            if (v != pa && std::abs(s[v] - s[0]) > d) {
                self(v, u);
            }
        }
    };
    dfs(0, -1);
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