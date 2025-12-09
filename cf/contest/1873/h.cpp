#include <bits/stdc++.h>

// Find UndirectedCycle
struct UndirectedCycle {
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<int> dfn, low;
    std::vector<bool> inCycle; 
    int cur;

    UndirectedCycle(int n = 0) { init(n); }

    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, 0);
        low.assign(n, 0);
        inCycle.assign(n, false);
        cur = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int parent) {
        dfn[u] = low[u] = ++cur;
        for (int v : adj[u]) {
            if (v == parent) continue;
            if (!dfn[v]) {
                dfs(v, u);
                low[u] = std::min(low[u], low[v]);
                if (low[v] <= dfn[u]) {
                    markCycle(u, v);
                }
            } else {
                low[u] = std::min(low[u], dfn[v]);
            }
        }
    }

    void markCycle(int u, int v) {
        inCycle[u] = inCycle[v] = true;
    }

    bool work() {
        for (int i = 0; i < n; i++) {
            if (!dfn[i]) dfs(i, -1);
        }
        for (bool x : inCycle) if (x) return true;
        return false;
    }
};

struct Edge {
    int to;
    long long w;
};

struct Dijkstra {
    int n;
    std::vector<std::vector<Edge>> adj;
    std::vector<long long> dist;
    std::vector<int> pre;

    Dijkstra(int n = 0) { init(n); }

    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        dist.assign(n, LLONG_MAX);
        pre.assign(n, -1);
    }

    void addEdge(int u, int v, long long w, bool directed = true) {
        adj[u].push_back({v, w});
        if (!directed) adj[v].push_back({u, w});
    }

    void run(int s) {
        dist.assign(n, LLONG_MAX);
        pre.assign(n, -1);
        std::priority_queue<std::pair<long long,int>, std::vector<std::pair<long long,int>>, std::greater<>> pq;
        dist[s] = 0;
        pq.push({0, s});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d != dist[u]) continue; 
            for (auto [v, w] : adj[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pre[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    std::vector<int> getPath(int t) {
        std::vector<int> path;
        if (dist[t] == LLONG_MAX) return path;
        for (int v = t; v != -1; v = pre[v]) path.push_back(v);
        std::reverse(path.begin(), path.end());
        return path;
    }
};


void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;
    a--, b--;
    std::vector<std::vector<int>> adj(n);
    UndirectedCycle scc(n);
    Dijkstra dj(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        scc.addEdge(u, v);
        dj.addEdge(u, v, 1, false);
    }
    dj.run(a);
    scc.work();
    int dis;
    int pos;
    [&](this auto&& self, int u, int pa, int dep) -> void {
        if (scc.inCycle[u]) {
            pos = u;
            dis = dep;
            return ;
        }
        for (int v: adj[u]) {
            if (v != pa) {
                self(v, u, dep + 1);
            }
        }
        return ;
    }(b, -1, 0);
    if (dj.dist[pos] <= dis) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
    }
    
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
