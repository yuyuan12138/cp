/**
 *      author:  yuyuan567
 *      created: 2025-08-21 23:43:17
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

/**   并查集（DSU）
 *    2023-08-04: https://ac.nowcoder.com/acm/contest/view-submission?submissionId=63239142
**/
struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};
struct Frame {
    int node, parent_node, parent_edge, next_idx;
    bool is_vis;
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt;
    std::cin >> tt;
    while (tt--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::pair<int, int>> edges(m+1);
        std::vector<std::vector<std::pair<int, int>>> adj(n);
        for (int i = 1; i <= m; i++) {
            int u, v;
            std::cin >> u >> v;
            u--, v--;
            edges[i] = {u, v};
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }
        std::vector<int> tin(n, 0), low(n, 0), vis(n, 0);
        std::vector<char> is_ok(m+1, 0);
        int t = 0;
        for (int s = 0; s < n; s++) {
            if (vis[s]) continue;
            std::vector<Frame> st;
            st.emplace_back(s, -1, -1, 0, false);
            while (!st.empty()) {
                Frame& f = st.back();
                int v = f.node;
                if (!f.is_vis) {
                    f.is_vis = true;
                    vis[v] = 1;
                    tin[v] = low[v] = ++t;
                }
                if (f.next_idx < (int) adj[v].size()) {
                    auto [to, eid] = adj[v][f.next_idx++];
                    if (eid == f.parent_edge) continue;
                    if (!vis[to]) {
                        st.emplace_back(to, v, eid, 0, false);
                    } else {
                        low[v] = std::min(low[v], tin[to]);
                    }
                } else {
                    st.pop_back();
                    if (f.parent_node != -1) {
                        int p = f.parent_node;
                        low[p] = std::min(low[p], low[v]);
                        if (low[v] > tin[p]) {
                            is_ok[f.parent_edge] = 1;
                        }
                    }
                }
            }
        }       
        DSU dsu(n);
        for (int i = 1; i <= m; i++) {
            if (!is_ok[i]) {
                dsu.merge(edges[i].first, edges[i].second);
            }
        }
        std::vector<int> compRep(n, -1);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);
            if (compRep[root] == -1) {
                compRep[root] = ++cnt;
            }
            compRep[i] = compRep[root];
        }
        std::vector<std::vector<std::pair<int, int>>> tr(cnt + 1);
        for (int i = 1; i <= m; i++) { 
            if (is_ok[i]) {
                int u = edges[i].first, v = edges[i].second;
                int cut = compRep[u], cvt = compRep[v];
                if (cut != cvt) {
                    tr[cut].emplace_back(cvt, i);
                    tr[cvt].emplace_back(cut, i);
                }
            }
        } 
        int c1 = compRep[dsu.find(0)]; 
        int cN = compRep[dsu.find(n-1)]; 
        std::vector<int> ans;
        int q;
        std::cin >> q;
        std::vector<int> queries(q);
        for (int i = 0; i < q; i++) {
            std::cin >> queries[i];
            queries[i]--; 
        }
        if (c1 == cN) {
            for (int i = 0; i < q; i++) {
                ans.push_back(-1);
            }
        } else {
            std::vector<int> pa(cnt + 1, -1), paE(cnt + 1, -1);
            std::queue<int> qq;
            qq.push(c1);
            pa[c1] = 0;
            while (!qq.empty()) {
                int v = qq.front(); qq.pop();
                for (auto& pe: tr[v]) {
                    int to = pe.first; int eid = pe.second;
                    if (pa[to] == -1) {
                        pa[to] = v;
                        paE[to] = eid;
                        qq.push(to);
                    }
                }
            }
            std::vector<int> pE;
            int cur = cN;
            while (cur != c1) {
                pE.push_back(paE[cur]);
                cur = pa[cur];
            }
            const int INF = 1e9;
            std::vector<int> bs(n, INF);
            for (int eid: pE) {
                int u = edges[eid].first, v = edges[eid].second;
                if (eid < bs[u]) {
                    bs[u] = eid;
                }
                if (eid < bs[v]) {
                    bs[v] = eid;
                }
            }
            std::queue<int> q2;
            std::vector<int> dis(n, -1), bI(n, INF);
            for (int i = 0; i < n; i++) {
                if (bs[i] != INF) {
                    dis[i] = 0;
                    bI[i] = bs[i];
                    q2.push(i);
                }
            }
            while (!q2.empty()) {
                int v = q2.front(); q2.pop();
                for (auto& pe: adj[v]) {
                    int to = pe.first;
                    if (dis[to] == -1) {
                        dis[to] = dis[v] + 1;
                        bI[to] = bI[v];
                        q2.push(to);
                    } else if (dis[to] == dis[v] + 1) {
                        if (bI[v] < bI[to]) {
                            bI[to] = bI[v];
                        }
                    }
                }
            }
            for (int ci: queries) {
                if (pE.empty()) {
                    ans.push_back(-1);
                } else {
                    ans.push_back(bI[ci] == INF ? -1 : bI[ci]);
                }
            }
        }
        for (int i = 0; i < (int)ans.size(); i++) {
            if (i) std::cout << ' ';
            std::cout << ans[i];
        }
        std::cout << '\n';
    }
    return 0;
}
