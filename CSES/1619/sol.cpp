/**
 *    author:  yuyuan
 *    created: 2025-12-11 17:33:58
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

  int n;
  cin >> n;
  vector<int> s(n), t(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> t[i];
  }
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  int i = 0, j = 0;
  int cur = 0, ans = 0;
  while (i < n && j < n) {
    if (s[i] < t[j]) {
      cur++;
      i++;
    } else if (s[i] == t[j]) {
      i++, j++;
    } else {
      cur--;
      j++;
    }
    ans = max(ans, cur);
  }
  cout << ans;
  

  return 0;
}

