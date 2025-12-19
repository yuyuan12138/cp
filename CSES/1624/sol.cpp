/**
 *    author:  yuyuan
 *    created: 2025-12-19 14:54:50
 **/
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

  const int n = 8;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<bool> col(n), left(2 * n + 1), right(2 * n + 1);
  int ans = 0;
  auto dfs = [&](auto&& self, int i) {
    if (i == n) {
      ans++;
      return ;
    }
    for (int j = 0; j < n; j++) {
      if (s[i][j] == '*' || col[j] || left[j - i + n] || right[j + i]) {
        continue;
      }
      col[j] = true;
      left[j - i + n] = true;
      right[j + i] = true;

      self(self, i + 1);

      col[j] = false;
      left[j - i + n] = false;
      right[j + i] = false;
    }
      return ;
  };
  dfs(dfs, 0);
  cout << ans << '\n';
  return 0;
}


