/**
 *      author:  yuyuan567
 *      created: 2025-08-06 15:34:00
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

struct DSU {
    std::vector<int> parent, size;
    int components;

    DSU(int n) : parent(n), size(n, 1), components(n) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return false;

        if (size[x] < size[y])
            std::swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        components--;
        return true;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    int get_size(int x) {
        return size[find(x)];
    }

    int count() const {
        return components;
    }
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> r(n);
    std::vector<std::vector<int>> g(n);
    for (int u = 0; u < n; u++) {
        std::cin >> r[u];
        r[u]--;
        g[r[u]].push_back(u);
    }
    std::vector<bool> on_cycle(n, false);
    auto dfs = [&](this auto&& dfs, int v) -> int {
        int h = 0;
        for (auto& u : g[v]) {
            if (on_cycle[u]) {
                continue;
            }
            if (on_cycle[v]) {
                h = std::max(h, dfs(u) + 1);
            } else {
                h = std::max(h, dfs(u) + 1);
            }
        }
        return h;
    };
    DSU dsu(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!dsu.unite(i, r[i])) {
            std::vector<int> cycle;
            int x = i;
            while (true) {
                cycle.push_back(x);
                on_cycle[x] = true;
                x = r[x];
                if (x == i) {
                    break;
                }
            }
            for (int v : cycle) {
                ans = std::max(ans, dfs(v));
            }
        }
    }
    std::cout << ans + 2 << "\n";

    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}