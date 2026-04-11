#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    s--, t--;
    std::vector<std::vector<int>> adj(n);
    std::vector<std::vector<int>> deg(n, std::vector<int> (n));
    std::vector<int> in(n);
    std::vector<bool> vis(n, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u][v]++;
        deg[v][u]++;
    }
    std::queue<int> q;
    q.push(t);
    vis[t] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (deg[u][v] >= 2) {
                if (!vis[v] && vis[u]) {
                    vis[v] = true;
                    q.push(v);
                }
            } else if (vis[u]) {
                in[v]++;
            }
            if (in[v] >= 2 && !vis[v]) {
                q.push(v);
                vis[v] = true;
            }
        }
    }
    std::cout << (vis[s] ? "Join Player" : "Cut Player") << '\n';
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