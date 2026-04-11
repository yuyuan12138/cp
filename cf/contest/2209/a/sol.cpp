/**
 *    author:  yuyuan
 *    created: 23.03.2026 15:33:58
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
  int tt;
  cin >> tt;
  while (tt--) {
    int64_t n, c, k;
    cin >> n >> c >> k;
    vector<int64_t> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      if (c - a[i] < 0) {
        continue;
      }
      int64_t add = min(k, c - a[i]);
      k -= add;
      c += add + a[i];
    }
    cout << c << '\n';
  }
  return 0;
}

