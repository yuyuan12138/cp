/**
 *    author:  yuyuan
 *    created: 2025-12-22 10:56:59
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

  int n;
  cin >> n;
  int64_t tot = int64_t(1 + n) * n / 2;
  for (int i = 0, x; i < n - 1; i++) {
    cin >> x;
    tot -= x;
  }
  cout << tot;

  return 0;
}


