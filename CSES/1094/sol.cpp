/**
 *    author:  yuyuan
 *    created: 2025-12-22 11:03:14
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
  int64_t ans = 0;
  int cur = 0;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    if (x < cur) {
      ans += cur - x;
    } else {
      cur = x;
    }
  }
  cout << ans;

  return 0;
}


