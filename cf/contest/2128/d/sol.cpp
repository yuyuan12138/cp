/**
 *      author:  yuyuan567
 *      created: 2025-09-02 00:58:28
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int64_t ans = 0;
    for (int k = 1; k <= n; k++) {
      ans += 1LL * k * (n - k + 1);
    }
    for (int i = 1; i < n; i++) {
      if (a[i - 1] < a[i]) {
        ans -= 1LL * i * (n - i);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
