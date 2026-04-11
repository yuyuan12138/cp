/**
 *      author:  yuyuan567
 *      created: 2025-09-11 10:20:56
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
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] != '#') continue;
      int cnt = 0;
      if (i > 0 && s[i - 1][j] == '#') {
        cnt++;
      }
      if (i < n - 1 && s[i + 1][j] == '#') {
        cnt++;
      }
      if (j > 0 && s[i][j - 1] == '#') {
        cnt++;
      }
      if (j < m - 1 && s[i][j + 1] == '#') {
        cnt++;
      }
      if (cnt != 2 && cnt != 4) {
        ok = false;
      }
    }
  }
  cout << (ok ? "Yes" : "No");
  return 0;
}
