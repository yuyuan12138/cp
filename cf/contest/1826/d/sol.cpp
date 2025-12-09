/**
 *      author:  yuyuan567
 *      created: 2025-09-03 23:49:20
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
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    vector<int> pre_max(n), suf_max(n);
    pre_max[0] = b[0] + 1;
    for (int i = 1; i < n; i++) {
      pre_max[i] = max(pre_max[i - 1], b[i] + i + 1);
    }
    suf_max[n - 1] = b[n - 1] - n;
    for (int i = n - 2; i >= 0; i--) {
      suf_max[i] = max(suf_max[i + 1], b[i] - i - 1);
    }
    int mx = 0;
    for (int i = 1; i < n - 1; i++) {
      mx = max(mx, pre_max[i - 1] + suf_max[i + 1] + b[i]);
    }
    cout << mx << '\n';
  }
  return 0;
}
