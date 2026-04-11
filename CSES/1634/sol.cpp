/**
 *    author:  yuyuan
 *    created: 2025-12-21 17:16:34
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

  int n, x;
  cin >> n >> x;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }

  vector<int> f(x + 1, inf);
  f[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int v = c[i]; v <= x; v++) {
      f[v] = min(f[v], f[v - c[i]] + 1);
    }
  }
  cout << (f[x] == inf ? -1 : f[x]);
  return 0;
}

