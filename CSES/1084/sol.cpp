/**
 *    author:  yuyuan
 *    created: 2025-12-10 16:08:07
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
  
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int cur_a = 0, cur_b = 0;
  int ans = 0;
  while (cur_a < n && cur_b < m) {
    while (cur_b < m && a[cur_a] - k > b[cur_b]) {
      cur_b++;
    }
    while (cur_a < n && a[cur_a] + k < b[cur_b]) {
      cur_a++;
    }
    if (cur_b < n && cur_b < m && abs(b[cur_b] - a[cur_a]) <= k) {
      ans++;
      cur_b++, cur_a++;
    }
  }
  cout << ans;

  return 0;
}

