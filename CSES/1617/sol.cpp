/**
 *    author:  yuyuan
 *    created: 24.03.2026 13:31:08
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

constexpr int MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  int x = 1;
  
  while (n--) {
    x = (x << 1) % MOD;
  }
  cout << x;

  return 0;
}
