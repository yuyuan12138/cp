/**
 *      author:  yuyuan567
 *      created: 2025-08-27 16:06:15
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
        if (n <= 3) {
            std::cout << "-1\n";
        } else {
            auto dijkstra = [&](int s) {
                std::vector<int> dis(n, -1), par(n, -1);
                std::queue<int> q;
                dis[s] = 0;
                q.push(s);
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (int& v: adj[u]) {
                        if (dis[v] == -1) {
                            dis[v] = dis[u] + 1;
                            par[v] = u;
                            q.push(v);
                        }
                    }
                }
                int far = 0;
                for (int i = 0; i < n; i++) {
                    if (dis[i] > dis[far]) {
                        far = i;
                    }
                }
                return std::tuple<int, std::vector<int>, std::vector<int>>(far, std::move(dis), std::move(par));
            };
            auto [x, d0, p0] = dijkstra(0);
            auto [y, dis, par] = dijkstra(x);
            if (dis[y] == n - 1) {
                std::cout << "-1\n";
            } else {
                std::vector<int> on(n);
                for (int cur = y; cur != -1; cur = par[cur]) {
                    on[cur] = 1;
                }
                int a = -1, b = -1, c = -1;
                for (int u = 0; u < n && a == -1; u++) {
                    if (!on[u]) continue;
                    for (int& v: adj[u]) {
                        if (!on[v]) {
                            b = u;
                            c = v;
                            a = par[u];
                            break;
                        }
                    }
                }
                std::cout << (a + 1) << " " << (b + 1) << " " << (c + 1) << '\n';
            }
        }
    }
    return 0;
}
