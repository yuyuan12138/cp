/**
 *    author:  yuyuan
 *    created: 2025-12-21 23:54:10
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

  int n, x;
  cin >> n >> x;
  vector<int> h(n), s(n);

  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  vector<int> f(x + 1);
  for (int i = 0; i < n; i++) {
    auto nf = f;
    for (int v = h[i]; v <= x; v++) {
      nf[v] = max(f[v], f[v - h[i]] + s[i]);
    }
    f = move(nf);
  }
  cout << f[x];

  return 0;
}

