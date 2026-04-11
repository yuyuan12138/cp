/**
 *    author:  yuyuan
 *    created: 2025-12-12 16:54:54
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

  int n;
  cin >> n;
  vector<int> k(n);
  for (int i = 0; i < n; i++) {
    cin >> k[i];
  }

  int ans = 1;
  set<int> vis;
  for (int i = 0, j = 0; i < n; i++) {
    while (j < n && !vis.contains(k[j])) {
      vis.insert(k[j]);
      j++;
    }
    ans = max(ans, j - i);
    vis.erase(vis.find(k[i]));
  }
  cout << ans;

  return 0;
}

