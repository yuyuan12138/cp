/**
 *    author:  yuyuan
 *    created: 2025-12-21 23:28:53
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
  vector<int> f(n + 1);
  for (int x = 1; x <= n; x++) {
    int mx = 0;
    int nx = x;
    while (nx) {
      mx = max(mx, nx % 10);
      nx /= 10;
    }
    f[x] = f[x - mx] + 1;
  }
  cout << f[n];

  return 0;
}

