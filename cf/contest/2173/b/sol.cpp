/**
 *    author:  yuyuan
 *    created: 2025-12-14 14:11:47
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

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    vector<vector<int64_t>> ans(n, vector<int64_t> (2));
    ans[0][0] = min(-a[0], b[0]);
    ans[0][1] = max(-a[0], b[0]);
    for (int i = 1; i < n; i++) {
      int64_t mn = ans[i - 1][0], mx = ans[i - 1][1];
      ans[i][0] = min(mn - a[i], int64_t(b[i]) - mx);
      ans[i][1] = max(mx - a[i], int64_t(b[i]) - mn);
    }

    cout << max(ans[n - 1][0], ans[n - 1][1]) << '\n';
  }

  return 0;
}


