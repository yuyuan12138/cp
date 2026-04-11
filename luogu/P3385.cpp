#include <bits/stdc++.h>

template <class T = int>
struct Edge {
    int u, v;
    T w;
};

template <class T = int>
struct BF {
    int n;
    std::vector<Edge<T>> edges;
    const T INF = std::numeric_limits<T>::max() / 2;

    BF(int n = 0) { init(n); }

    void init(int n_) {
        n = n_;
        edges.clear();
    }

    void addEdge(int u, int v, T w) {
        edges.push_back({u, v, w});
    }

    bool hasNegCycle() {
        std::vector<T> dist(n, 0); 
        int x = -1;
        for (int i = 0; i < n; i++) {
            x = -1;
            for (auto &e : edges) {
                if (dist[e.v] > dist[e.u] + e.w) {
                    dist[e.v] = std::max(-INF, dist[e.u] + e.w);
                    x = e.v;
                }
            }
        }
        return x != -1;
    }

    bool canReachNegCycle(int s) {
        std::vector<T> dist(n, INF);
        dist[s] = 0;
        int x = -1;
        for (int i = 0; i < n; i++) {
            x = -1;
            for (auto &e : edges) {
                if (dist[e.u] < INF && dist[e.v] > dist[e.u] + e.w) {
                    dist[e.v] = std::max(-INF, dist[e.u] + e.w);
                    x = e.v;
                }
            }
        }
        if (x == -1) return false; 

        std::vector<int> vis(n);
        std::queue<int> q;
        q.push(x);
        vis[x] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (dist[u] < INF) return true; 
            for (auto &e : edges) {
                if (e.u == u && !vis[e.v]) {
                    vis[e.v] = 1;
                    q.push(e.v);
                }
            }
        }
        return false;
    }
};


using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    BF<i64> bf(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        i64 w;
        std::cin >> u >> v >> w;
        u--, v--;
        bf.addEdge(u, v, w);
        if (w >= 0) {
            bf.addEdge(v, u, w);
        }
    }
    
    std::cout << (bf.canReachNegCycle(0) ? "YES\n" : "NO\n");
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
