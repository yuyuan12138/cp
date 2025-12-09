template <class t = int>
struct edge {
  int u, v;
  t w;
};

template <class t = int>
struct BF {
  int n;
  std::vector<edge<t>> edges;
  const t inf = std::numeric_limits<t>::max() / 2;

  BF(int n = 0) { init(n); }

  void init(int n_) {
    n = n_;
    edges.clear();
  }

  void addedge(int u, int v, t w) {
    edges.push_back({u, v, w});
  }

  bool hasnegcycle() {
    std::vector<t> dist(n, 0); 
    int x = -1;
    for (int i = 0; i < n; i++) {
      x = -1;
      for (auto &e : edges) {
        if (dist[e.v] > dist[e.u] + e.w) {
          dist[e.v] = std::max(-inf, dist[e.u] + e.w);
          x = e.v;
        }
      }
    }
    return x != -1;
  }

  bool canreachnegcycle(int s) {
    std::vector<t> dist(n, inf);
    dist[s] = 0;
    int x = -1;
    for (int i = 0; i < n; i++) {
      x = -1;
      for (auto &e : edges) {
        if (dist[e.u] < inf && dist[e.v] > dist[e.u] + e.w) {
          dist[e.v] = std::max(-inf, dist[e.u] + e.w);
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
      if (dist[u] < inf) return true; 
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
