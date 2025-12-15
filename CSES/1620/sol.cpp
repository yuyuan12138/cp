/**
 *    author:  yuyuan
 *    created: 2025-12-15 11:14:44
 **/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

constexpr int64_t inf = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, t;
  cin >> n >> t;
  vector<int> k(n);
  for (int i = 0; i < n; i++) {
    cin >> k[i];
  } 

  auto check = [&](int64_t x) -> bool {
    int64_t tot = 0;
    for (int i = 0; i < n; i++) {
      if (tot >= inf) {
        return true;
      }
      tot += x / k[i];
    }
    return tot >= t;
  };
  int64_t lo = 1, hi = inf;
  while (lo <= hi) {
    int64_t mid = lo + (hi - lo) / 2;
    if (check(mid)) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << lo;

  return 0;
}


