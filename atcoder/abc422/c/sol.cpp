/**
 *      author:  yuyuan567
 *      created: 2025-09-11 10:25:58
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
    int64_t a, b, c;
    cin >> a >> b >> c;
    cout << min({a, c, (a + b + c) / 3}) << '\n';
  }
  return 0;
}
