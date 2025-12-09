struct Edge {
    int to;
    int64_t w;
};

struct Dijkstra {
    int n;
    std::vector<std::vector<Edge>> adj;
    std::vector<int64_t> dist;
    std::vector<int> pre;

    Dijkstra(int n = 0) { init(n); }

    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        dist.assign(n, INT64_MAX);
        pre.assign(n, -1);
    }

    void addEdge(int u, int v, int64_t w, bool directed = true) {
        adj[u].push_back({v, w});
        if (!directed) adj[v].push_back({u, w});
    }

    void run(int s) {
        dist.assign(n, LLONG_MAX);
        pre.assign(n, -1);
        std::priority_queue<std::pair<int64_t, int>, std::vector<std::pair<int64_t, int>>, std::greater<>> pq;
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