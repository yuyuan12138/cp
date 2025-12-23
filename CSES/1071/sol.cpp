/**
 *    author:  yuyuan
 *    created: 2025-12-23 08:47:09
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

  int t;
  cin >> t;
  while (t--) {
    int y, x;
    cin >> y >> x;
    int mx = max(y, x);
    if (mx % 2 == 0) {
      if (y < x) {
        cout << int64_t(x - 1) * (x - 1) + y << '\n';
      } else {
        cout << int64_t(y) * y - x + 1 << '\n';
      }
    } else {
      if (y < x) {
        cout << int64_t(x) * x - y + 1 << '\n';
      } else {
        cout << int64_t(y - 1) * (y - 1) + x << '\n';
      }
    }
  }

  return 0;
}


