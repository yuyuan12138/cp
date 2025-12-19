/**
 *    author:  yuyuan
 *    created: 2025-12-19 17:24:01
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

  int n, k;
  cin >> n >> k;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  
  auto check = [&](int64_t s) -> bool {
    int cnt = 1;
    int64_t cur = 0;
    for (int i = 0; i < n; i++) {
      if (s < x[i]) {
        return false;
      }
      if (cur + x[i] > s) {
        cnt++;
        cur = 0; 
      }
      cur += x[i];
    }
    return cnt <= k;
  };
  int64_t l = 0, r = 1e18, ans = 0;
  while (l <= r) {
    int64_t mid = l + (r - l) / 2;
    if (check(mid)) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << ans;

  return 0;
}


