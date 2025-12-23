/**
 *    author:  yuyuan
 *    created: 2025-12-23 08:58:34
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
  for (int k = 1; k <= n; k++) {
    if (k == 1) {
      cout << 0 << '\n';
    } else if (k == 2) {
      cout << 6 << '\n';
    } else {
      cout << int64_t(k) * k * (k * k - 1) / 2 - (k - 2) * (k - 1) * 2 * 2 << '\n';
    }
  }
  return 0;
}


