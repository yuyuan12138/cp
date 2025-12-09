/**
 *      author:  yuyuan567
 *      created: 2025-09-10 08:07:24
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
    int a, b;
    cin >> a >> b;
    int x = lcm(a, b);
    int cnt = 2;
    if (a == x) {
      cnt--;
    }
    if (b == x) {
      cnt--;
    }
    cout << cnt << "\n";
  }
  return 0;
}
