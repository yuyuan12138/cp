/**
 *    author:  yuyuan
 *    created: 2025-12-12 10:23:49
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
  int64_t tot = 0;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  sort(x.begin(), x.end());
  int64_t ans = 0;
  for (int i = 0; i < n; i++) {
    if (tot + 1 < x[i]) {
      ans = tot + 1;
      break;
    }
    tot += x[i];
  }
  cout << (ans == 0LL ? tot + 1 : ans);

  return 0;
}


