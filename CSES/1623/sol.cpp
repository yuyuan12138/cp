/**
 *    author:  yuyuan
 *    created: 2025-12-17 17:03:17
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
  vector<int> a(n);
  int64_t tot = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    tot += a[i];
  }
  int64_t ans = INT64_MAX; 
  auto dfs = [&](auto&& self, int64_t s, int idx) {
    if (idx == n) {
      ans = std::min(ans, abs(tot - s - s));
      return ;
    }
    self(self, s + a[idx], idx + 1);
    self(self, s, idx + 1);
  };
  dfs(dfs, 0, 0);
  cout << ans;

  return 0;
}


