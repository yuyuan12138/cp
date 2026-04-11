/**
 *      author:  yuyuan567
 *      created: 2025-09-04 08:15:37
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
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<int>> pref_sum(26, vector<int>(n + 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      pref_sum[j][i + 1] += pref_sum[j][i];
      if (j == s[i] - 'a') {
        pref_sum[j][i + 1]++;
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
      cnt += (pref_sum[i][r + 1] - pref_sum[i][l] > 0);
    }
    cout << (l == r || cnt >= 3 || s[l] != s[r] ? "Yes\n" : "No\n");
  }
  return 0;
}
