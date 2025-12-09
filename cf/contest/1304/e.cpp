#include <bits/stdc++.h>

struct HLD {
    int n;
    std::vector<int> siz, top, dep, parent, in, out, seq;
    std::vector<std::vector<int>> adj;
    int cur;
    
    HLD() {}
    HLD(int n) {
        init(n);
    }
    void init(int n) {
        this->n = n;
        siz.resize(n);
        top.resize(n);
        dep.resize(n);
        parent.resize(n);
        in.resize(n);
        out.resize(n);
        seq.resize(n);
        cur = 0;
        adj.assign(n, {});
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void work(int root = 0) {
        top[root] = root;
        dep[root] = 0;
        parent[root] = -1;
        dfs1(root);
        dfs2(root);
    }
    void dfs1(int u) {
        if (parent[u] != -1) {
            adj[u].erase(std::find(adj[u].begin(), adj[u].end(), parent[u]));
        }
        
        siz[u] = 1;
        for (auto &v : adj[u]) {
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[adj[u][0]]) {
                std::swap(v, adj[u][0]);
            }
        }
    }
    void dfs2(int u) {
        in[u] = cur++;
        seq[in[u]] = u;
        for (auto v : adj[u]) {
            top[v] = v == adj[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;
    }
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                u = parent[top[u]];
            } else {
                v = parent[top[v]];
            }
        }
        return dep[u] < dep[v] ? u : v;
    }
    
    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    
    int jump(int u, int k) {
        if (dep[u] < k) {
            return -1;
        }
        
        int d = dep[u] - k;
        
        while (dep[top[u]] > d) {
            u = parent[top[u]];
        }
        
        return seq[in[u] - dep[u] + d];
    }
    
    bool isAncester(int u, int v) {
        return in[u] <= in[v] && in[v] < out[u];
    }
    
    int rootedParent(int u, int v) {
        std::swap(u, v);
        if (u == v) {
            return u;
        }
        if (!isAncester(u, v)) {
            return parent[u];
        }
        auto it = std::upper_bound(adj[u].begin(), adj[u].end(), v, [&](int x, int y) {
            return in[x] < in[y];
        }) - 1;
        return *it;
    }
    
    int rootedSize(int u, int v) {
        if (u == v) {
            return n;
        }
        if (!isAncester(v, u)) {
            return siz[v];
        }
        return n - siz[rootedParent(u, v)];
    }
    
    int rootedLca(int a, int b, int c) {
        return lca(a, b) ^ lca(b, c) ^ lca(c, a);
    }
};


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  HLD hld(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    std::cin >> u >> v;
    u--, v--;
    hld.addEdge(u, v);
  }
  hld.work(0);
  int q;
  std::cin >> q;
  while (q--) {
    int x, y, a, b, k;
    std::cin >> x >> y >> a >> b >> k;
    x--, y--, a--, b--;
    if (k >= hld.dist(a, b) && (k - hld.dist(a, b)) % 2 == 0) {
      std::cout << "YES\n";
    } else {
      int disa_x = hld.dist(a, x);
      int disb_y = hld.dist(b, y);
      if (k >= (disa_x + disb_y + 1) && (k - disa_x - disb_y - 1) % 2 == 0) {
        std::cout << "YES\n";
      } else {
        int disa_y = hld.dist(a, y);
        int disb_x = hld.dist(b, x);
        if (k >= (disa_y + disb_x + 1) && (k - disa_y - disb_x - 1) % 2 == 0) {
          std::cout << "YES\n";
        } else {
          std::cout << "NO\n";
        }
      }
    }
  }
  return 0;
}