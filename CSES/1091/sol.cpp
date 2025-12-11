/**
 *    author:  yuyuan
 *    created: 2025-12-10 21:26:01
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

  int n, m;
  cin >> n >> m;
  multiset<int> vis;
  vector<int> h(n), t(m);

  for (int i = 0; i < n; i++) {
    cin >> h[i];
    vis.insert(h[i]);
  }
  for (int i = 0; i < m; i++) {
    cin >> t[i];
  }
  
  int cur = 0;
  for (int i = 0; i < m; i++) {
    if (vis.lower_bound(t[i]) == vis.end()) {
      cout << -1 < '\n';
    } else {

    }
  }

  return 0;
}


