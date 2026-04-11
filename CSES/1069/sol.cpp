/**
 *    author:  yuyuan
 *    created: 2025-12-22 10:59:18
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

  string s;
  cin >> s;
  const int n = s.size();
  int cur = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != s[cur]) {
      cur = i;
    }
    ans = max(ans, i - cur + 1);
  }
  cout << ans;

  return 0;
}


