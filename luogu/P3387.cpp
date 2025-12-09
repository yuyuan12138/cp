#include <bits/stdc++.h>

using i64 = long long;

struct SCC {
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<int> stk;
    std::vector<int> dfn, low, bel;
    std::vector<int> compSize;  // 每个强连通分量的大小
    int cur, cnt;

    SCC() {}
    SCC(int n) { init(n); }

    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.resize(n);
        bel.assign(n, -1);
        stk.clear();
        compSize.clear();
        cur = cnt = 0;
    }

    void addEdge(int u, int v) { adj[u].push_back(v); }

    void dfs(int x) {
        dfn[x] = low[x] = cur++;
        stk.push_back(x);

        for (auto y : adj[x]) {
            if (dfn[y] == -1) {
                dfs(y);
                low[x] = std::min(low[x], low[y]);
            } else if (bel[y] == -1) {
                low[x] = std::min(low[x], dfn[y]);
            }
        }

        if (dfn[x] == low[x]) {
            int y;
            int sz = 0;  
            do {
                y = stk.back();
                bel[y] = cnt;
                stk.pop_back();
                sz++;
            } while (y != x);
            compSize.push_back(sz);  
            cnt++;
        }
    }

    std::vector<int> work() {
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                dfs(i);
            }
        }
        return bel;
    }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    SCC scc(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        scc.addEdge(u, v);
    }

    std::vector<int> res = scc.work();

    std::vector<i64> tot(n);
    for (int i = 0; i < n; i++) {
        tot[res[i]] += a[i];
    }

    

    return 0;
}