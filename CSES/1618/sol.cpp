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
  int ans = 0;
  while (n) {
    ans += n / 5;
    n /= 5;
  }
  cout << ans;
  return 0;
}
