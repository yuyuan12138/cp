/**
 *      author:  yuyuan567
 *      created: 2025-09-03 16:19:02
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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int64_t> pref_sum(n + 1), suff_sum(n + 1);
  for (int i = 0; i < n; i++) {
    pref_sum[i + 1] = gcd(pref_sum[i], a[i]);
  }
  for (int i = n - 1; i >= 0; i--) {
    suff_sum[i] = gcd(suff_sum[i + 1], a[i]);
  }
  int64_t mx = 0;
  for (int i = 0; i < n; i++) {
    mx = max(mx, gcd(pref_sum[i], suff_sum[i + 1]));
  }
  cout << mx;
  return 0;
}
