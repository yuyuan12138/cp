/**
 *    author:  yuyuan
 *    created: 26.03.2026 19:55:59
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, d;
    cin >> n >> m >> d;
    int c = d / m + 1;
    cout << (n + c - 1) / c << '\n';
  }
  return 0;
}
