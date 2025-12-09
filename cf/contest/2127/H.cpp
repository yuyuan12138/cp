/**
 *      author:  yuyuan567
 *      created: 2025-08-14 00:44:47
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

struct Graph {
    int N;
    std::vector<std::vector<int>> g;
    std::vector<int> match, p, base, q, used, blossom;
    int qh, qt;

    Graph(int n = 0): N(n), g(n) {}

    void add_edge(int u, int v) {
        if (u == v) return;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int lca(int a, int b) {
        std::vector<int> used_lca(N, 0);
        while (true) {
            a = base[a];
            used_lca[a] = 1;
            if (match[a] == -1) break;
            a = p[match[a]];
        }
        while (true) {
            b = base[b];
            if (used_lca[b]) return b;
            if (match[b] == -1) break;
            b = p[match[b]];
        }
        return -1;
    }

    void markPath(int v, int b, int children) {
        while (base[v] != b) {
            blossom[base[v]] = blossom[base[match[v]]] = 1;
            p[v] = children;
            children = match[v];
            v = p[match[v]];
        }
    }

    int findPath(int root) {
        used.assign(N, 0);
        p.assign(N, -1);
        for (int i = 0; i < N; ++i) base[i] = i;
        qh = qt = 0;
        q[qt++] = root;
        used[root] = 1;
        while (qh < qt) {
            int v = q[qh++];
            for (int u : g[v]) {
                if (base[v] == base[u] || match[v] == u) continue;
                if (u == root || (match[u] != -1 && p[match[u]] != -1)) {
                    int curbase = lca(v, u);
                    blossom.assign(N, 0);
                    markPath(v, curbase, u);
                    markPath(u, curbase, v);
                    for (int i = 0; i < N; ++i)
                        if (blossom[base[i]]) {
                            base[i] = curbase;
                            if (!used[i]) {
                                used[i] = 1;
                                q[qt++] = i;
                            }
                        }
                } else if (p[u] == -1) {
                    p[u] = v;
                    if (match[u] == -1) {
                        // Augment
                        int cur = u;
                        while (cur != -1) {
                            int prev = p[cur];
                            int next = (prev == -1 ? -1 : match[prev]);
                            match[cur] = prev;
                            if (prev != -1) match[prev] = cur;
                            cur = next;
                        }
                        return 1;
                    } else {
                        used[match[u]] = 1;
                        q[qt++] = match[u];
                    }
                }
            }
        }
        return 0;
    }

    int solve() {
        match.assign(N, -1);
        base.resize(N);
        q.resize(N);
        int ans = 0;
        for (int i = 0; i < N; ++i)
            if (match[i] == -1)
                ans += findPath(i);
        return ans;
    }
};


int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int tt = 1;
    std::cin >> tt;
    while(tt--) {
        int n, m;
        std::cin >> n >> m;
        Graph g(2 * n + 2 * m);
        for (int i = 0; i < m; i++) {
            int u, v;
            std::cin >> u >> v;
            u--, v--;
            int ae = 2 * n + i;
            int be = 2 * n + m + i;
            g.add_edge(ae, be);
            g.add_edge(ae, 2 * u);
            g.add_edge(ae, 2 * u + 1);
            g.add_edge(be, 2 * v);
            g.add_edge(be, 2 * v + 1);
        }
        // ll ans = g.solve() - m;
        std::cout << g.solve() - m << "\n";
        
    }
    return 0;
}