/**
 *      author:  yuyuan567
 *      created: 2025-08-04 00:58:59
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "../../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<ll> b(n);
    std::vector<std::vector<std::pair<int, ll>>> edges(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    ll mx = 0;
    ll mn = INT64_MAX - 4;
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        std::cin >> u >> v >> w;
        u--;
        v--;
        edges[u].push_back({v, w});
        mx = std::max(mx, w);
        mn = std::min(mn, w);
    }
    std::vector<ll> vis(n);
    ll l = mn, r = mx;

    auto check = [&](ll x) -> bool {
        for (int i = 0; i < n; i++) {
            vis[i] = 0;
        }
        for (int u = 0; u < n; u++) {
            if (u > 0 && vis[u] == 0) {
                continue;
            }
            vis[u] = std::min(x, vis[u] + b[u]);
            for (auto& [v, w] : edges[u]) {
                if (vis[u] >= w) {
                    vis[v] = std::max(vis[v], vis[u]);
                }
            }
        }
        if (vis[n - 1]) {
            return true;
        } else {
            return false;
        }
    };

    while (l <= r) {
        ll mid = l + (r - l) / 2;

        if (check(mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    std::cout << ((l > mx || l < mn) ? -1 : l) << "\n";
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}