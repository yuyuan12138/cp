/**
 *      author:  yuyuan567
 *      created: 2025-09-10 08:37:04
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    debug(a);
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
      debug(ans);
      ans += int64_t(a[i]) * max(0, m - i);
    }
    cout << ans << '\n';
  }
  return 0;
}
