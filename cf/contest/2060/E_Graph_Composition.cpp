/**
 *      author:  yuyuan567
 *      created: 2025-08-15 00:00:19
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;


struct DSU {
    std::vector<int> parent, size;
    int components;

    DSU(int n) : parent(n), size(n, 1), components(n) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;

        if (size[x] < size[y]) std::swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        components--;
        return true;
    }

    bool is_same(int x, int y) {
        return find(x) == find(y);
    }

    int get_size(int x) {
        return size[find(x)];
    }

    int count() const {
        return components;
    }
};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt;
    std::cin >> tt;
    while (tt--) {
        int n, m1, m2;
        std::cin >> n >> m1 >> m2;
        
        DSU dsu(n);

        DSU dsu2(n);

        std::vector<std::pair<int, int>> edges(m1);
        for (int i = 0; i < m1; i++) {
            int u, v;
            std::cin >> u >> v;
            u--, v--;
            edges[i] = {u, v};
        }

        for (int i = 0; i < m2; i++) {
            int u, v;
            std::cin >> u >> v;
            u--, v--;
            dsu.merge(u, v);
        }
        
        ll ans = 0;
        // std::vector<int> root(n, -1);
        for (int i = 0; i < m1; i++) {
            auto [u, v] = edges[i];
            if (!dsu.is_same(u, v)) {
                ans++;
            } else {
                dsu2.merge(u, v);
            }
        }
        ll f = 0;
        ll g = 0;
        for (int i = 0; i < n; i++) {
            if (i == dsu2.find(i)) {
                f++;
            }
            if (i == dsu.find(i)) {
                g++;
            }
        }
        std::cout << ans + f - g << "\n";
        

    }

    return 0;
}