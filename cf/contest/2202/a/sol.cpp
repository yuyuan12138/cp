/**
 *    author:  yuyuan
 *    created: 24.03.2026 10:38:08
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
    int x, y;
    cin >> x >> y;
    int dx = 0;
    if (y < 0) {
      dx = -4 * y;
    } else if (y > 0) {
      dx = 2 * y;
    }
    if (x < dx) {
      cout << "NO\n";
    } else {
      x -= dx;
      if (x % 3 == 0) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
  return 0;
}

