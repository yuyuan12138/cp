/**
 *    author:  yuyuan
 *    created: 2025-12-18 23:27:57
 **/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("factory.in", "r", stdin);
  freopen("factory.out", "w", stdout);

  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[v].push_back(u);
  }
  
  int ans = -1;
  for (int u = 0; u < n; u++) {
    set<int> vis;
    auto dfs = [&](auto&& self, int u) -> void {
      if (vis.count(u)) {
        return ;
      }
      vis.insert(u);
      for (int v : adj[u]) {
        self(self, v);
      }
      return ;
    };
    dfs(dfs, u);
    if (vis.size() == n) {
      ans = u + 1;
      break;
    }
  }
  cout << ans;
  return 0;
}

