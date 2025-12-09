#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    a[i]--;
  }
  std::vector<std::vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  std::vector<bool> vis(n, false);
  std::vector<std::vector<int>> dis(k);
  std::queue<int> q;
  q.push(0);
  vis[0] = true;
  int dep = 0;
  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
      int u = q.front();
      q.pop();
      dis[a[u]].push_back(dep);
      for (int v : adj[u]) {
        if (vis[v]) {
          continue;
        }
        vis[v] = true;
        q.push(v);
      }
    }
    dep++;
  }
  for (int i = 0; i < k; i++) {
    int max = 0;
    for (int val : dis[i]) {
      max = std::max(val, max);
    }
    std::cout << max << " ";
  }
  return 0;
}
