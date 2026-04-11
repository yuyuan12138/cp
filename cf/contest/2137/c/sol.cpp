/**
 *      author:  yuyuan567
 *      created: 2025-09-08 11:29:17
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
  int tt;
  cin >> tt;
  while (tt--) {
    int64_t a, b;
    cin >> a >> b;
    if (b == 1) {
      if ((a + b) % 2 == 1) {
        cout << "-1\n";
      } else {
        cout << a + b << '\n';
      }
    } else if (a * b % 2 == 1) {
      cout << a * b + 1 << '\n';
    } else {
      if (b % 2 == 1 || (a * b / 2 % 2 == 1)) {
        cout << "-1\n";
      } else {
        cout << a * b / 2 + 2 << '\n';
      }
    }
  }
  return 0;
}
