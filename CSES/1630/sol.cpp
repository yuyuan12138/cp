/**
 *    author:  yuyuan
 *    created: 2025-12-15 11:43:09
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
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end());
  int64_t cur = 0;
  int64_t ans = 0;
  for (int i = 0; i < n; i++) {
    cur += a[i].first;
    ans += a[i].second - cur;
  }
  cout << ans;

  return 0;
}


