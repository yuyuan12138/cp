/**
 *    author:  yuyuan
 *    created: 2025-12-09 21:44:48
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

  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }

    vector<int64_t> L(n), R(n);
    int64_t cur = -inf;
    for (int i = 0; i < n; i++) {
      cur = max(int64_t(a[i]), cur + a[i]);
      L[i] = cur;
    }
    cur = -inf;
    for (int i = n - 1; i >= 0; i--) {
      cur = max(int64_t(a[i]), cur + a[i]);
      R[i] = cur;
    }
    int64_t ans = -inf;
    for (int i = 0; i < n; i++) {
      ans = max(ans, L[i] + R[i] - a[i]);
    }
    if (k % 2 == 1) {
      for (int i = 0; i < n; i++) {
        ans = max(ans, L[i] + R[i] - a[i] + b[i]);
      }
    }
    cout << ans << '\n';
  }

  return 0;
}


