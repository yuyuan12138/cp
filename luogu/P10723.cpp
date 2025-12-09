#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> is_black(n);
  int root = -1;
  for (int i = 0; i < n; i++) {
    std::cin >> is_black[i];
    if (is_black[i]) {
      root = i;
    }
  }
  std::vector<std::vector<int>> adj(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    std::cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if (root == -1) {
    std::cout << 0 << '\n';
  } else {
    std::vector<int> f(n);
    auto dfs = [&](this auto&& self, int u, int pa) -> void {
      int cnt = 0;
      for (int v : adj[u]) {
        if (v != pa) {
          self(v, u);
          cnt += f[v];
        }
      }
      if (cnt == 0) {
        for (int v : adj[u]) {
          if (v != pa && is_black[v] && !is_black[u]) {
            cnt = 1;
          }
        }
        f[u] = cnt;
      } else if (!is_black[u]) {
        f[u] = cnt + 1;
      } else {
        f[u] = cnt;
      }
    };
    dfs(root, -1);
    for (int i = 0; i < n; i++) {
      std::cerr << "f[i]: " << f[i] << " \n"[i == n - 1];
    }
    std::cout << f[root];
  }
  return 0;
}
