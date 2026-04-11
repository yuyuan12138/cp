#include <bits/stdc++.h>

constexpr int inf = 1e9;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  if (m == 0) {
    std::cout << n << '\n';
    return 0;
  }
  std::vector<int> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    u--, v--;
    adj[u] |= (1 << v);
    adj[v] |= (1 << u);
  }

  std::vector<int> f(1 << n, inf);
  for (int mask = 0; mask < (1 << n); mask++) {
    bool ok = true;
    for (int u = 0; u < n; u++) {
      if ((1 << u) & mask) {
        if (((adj[u] | (1 << u)) & mask) != mask) {
          ok = false;
        }
      }
    }
    if (ok) {
      f[mask] = 1;
    }
  }

  for (int mask = 0; mask < (1 << n); mask++) {
    for (int submask = mask; submask; submask = (submask - 1) & mask) {
      int subset = mask ^ submask;
      if (f[subset] != inf && f[submask] != inf) {
        f[mask] = std::min(f[mask], f[subset] + f[submask]);
      }
    }
  }

  std::cout << f[(1 << n) - 1];

  return 0;
}