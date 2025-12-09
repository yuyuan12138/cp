/**
 *      author:  yuyuan567
 *      created: 2025-09-11 09:27:07
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
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] - '0' == 1) {
        cnt++;
      }
    }
    int ans = 0;
    for (int i = 0; i < cnt; i++) {
      if (s[n - i - 1] - '0' == 0) {
        ans++;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
