/**
 *    author:  yuyuan
 *    created: 24.03.2026 13:35:09
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
  int n;
  cin >> n;
  int cnt = 0;
  while (n) {
    cnt += (n >= 5);
    n /= 5;
  }
  cout << 5 * int64_t(cnt) * (cnt - 1) / 2;
  return 0;
}
