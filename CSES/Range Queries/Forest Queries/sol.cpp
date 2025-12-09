/**
 *      author:  yuyuan567
 *      created: 2025-09-05 02:54:52
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
  int n, q;
  cin >> n >> q;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<vector<int>> pref_sum(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      pref_sum[i][j] = pref_sum[i - 1][j] + pref_sum[i][j - 1] -
                       pref_sum[i - 1][j - 1] + (s[i - 1][j - 1] == '*');
    }
  }
  while (q--) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    cout << pref_sum[a][b] - pref_sum[a][y - 1] - pref_sum[x - 1][b] +
                pref_sum[x - 1][y - 1]
         << "\n";
  }
  return 0;
}
