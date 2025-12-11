/**
 *    author:  yuyuan
 *    created: 2025-12-11 18:29:17
 **/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

constexpr int inf = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int64_t ans = -inf;
  int64_t cur = -inf;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    cur = max(int64_t(x), cur + x);
    ans = max(ans, cur);
  }
  cout << ans;

  return 0;
}

