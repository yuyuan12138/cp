/**
 *      author:  yuyuan567
 *      created: 2025-09-03 15:53:43
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
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      a[i] = s[i] - '0';
    }
    map<int64_t, int64_t> mp;
    int64_t ans = 0;
    vector<int64_t> pref_sum(n + 1);
    for (int i = 0; i < n; i++) {
      pref_sum[i + 1] = pref_sum[i] + a[i];
    }
    for (int i = 0; i <= n; i++) {
      ans += mp[pref_sum[i] - i];
      mp[pref_sum[i] - i]++;
    }
    cout << ans << '\n';
  }
  return 0;
}
