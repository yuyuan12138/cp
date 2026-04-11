/**
 *      author:  yuyuan567
 *      created: 2025-09-02 10:46:38
 */
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
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> y[i];
  }
  int64_t ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ans = std::max(ans, 1LL * (x[i] - x[j]) * (x[i] - x[j]) +
                              (y[i] - y[j]) * (y[i] - y[j]));
    }
  }
  cout << ans;
  return 0;
}
