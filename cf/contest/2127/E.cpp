/**
 *      author:  yuyuan567
 *      created: 2025-08-14 11:13:24
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;


int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int tt = 1;
    std::cin >> tt;
    while(tt--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<std::vector<int>> adj(n);
        std::vector<int> w(n), c(n);
        for (int i = 0; i < n; i++) std::cin >> w[i];
        for (int i = 0; i < n; i++) std::cin >> c[i];

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            std::cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        ll ans = 0;
        std::vector<std::set<int>> s(n);
        auto color = [&](this auto&& self, int x, int p) -> void {
            c[x] = c[p];
            for (int y: adj[x]) {
                if (y == p) {
                    continue;
                }
                if (!c[y]) {
                    self(y, x);
                }
            }
        };

        [&](this auto&& self, int u, int p) -> void {
            std::vector<int> a;
            for (int v: adj[u]) {
                if (v == p) continue;
                self(v, u);

                if (s[u].size() < s[v].size()) {
                    std::swap(s[u], s[v]);
                }
                for (int v: s[v]) {
                    if (s[u].contains(v)) {
                        a.push_back(v);
                    } else {
                        s[u].insert(v);
                    }
                }
            }
            std::sort(a.begin(), a.end());

            a.erase(std::unique(a.begin(), a.end()), a.end());
            if (a.size() > 1 || (a.size() == 1 && c[u] && a[0] != c[u])) {
                ans += w[u];
            }

            if (c[u]) {
                s[u].insert(c[u]);
            } else if (!a.empty()) {
                c[u] = a[0];
            } else if (!s[u].empty()) {
                c[u] = *s[u].begin();
            }
            if (c[u]) {
                for (int v: adj[u]) {
                    if (v == p) {
                        continue;
                    }
                    if (!c[v])
                        color(v, u);
                }
            }
        }(0, -1);
        std::cout << ans << "\n";
        for (int i = 0; i < n; i++) {
            std::cout << (c[i] != 0 ? c[i] : 1) << " ";
        }
        std::cout << "\n";
    }
    
    return 0;
}