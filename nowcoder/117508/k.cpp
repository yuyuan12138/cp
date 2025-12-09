#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 rand_num(seed);
    
    int n, k;
    std::cin >> n >> k;
    std::uniform_int_distribution<int> dist(0, k - 1);
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    std::vector<int> a(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        i64 w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    
    i64 ans = 0;


    int tt = 300;

    while (tt--) {
        std::vector<int> colors(n);
        for (int i = 0; i < n; i++) {
            colors[i] = dist(rand_num);
        }
        i64 res = 0;
        std::vector<std::vector<i64>> f(n, std::vector<i64> (1 << k, LLONG_MIN / 4));
        auto dfs = [&](auto&& self, int u, int pa) -> void {
            f[u][0] = f[u][1 << colors[a[u]]] = 0;
            for (auto [v, w] : adj[u]) {
                if (pa != v) {
                    self(self, v, u);
                    for (int s = 1; s < (1 << k); s++) {
                        f[v][s] += w;
                    }
                    for (int s = (1 << k) - 1; s >= 0; s--) {
                        for (int t = s; t; t = (t - 1) & s) {
                            f[u][s] = std::max(f[u][s], f[u][s ^ t] + f[v][t]);
                            if (s ^ t) {
                                res = std::max(res, f[u][s ^ t] + f[v][t]);
                            }
                        }
                    }
                }
            }
            return ;
        };
        dfs(dfs, 0, -1);
        ans = std::max(ans, res);
    }

    std::cout << ans;
    
    return 0;
}