/**
 *    author:  yuyuan
 *    created: 2025-12-14 14:04:33
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

  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    string s;
    cin >> s;
    int cur = k;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        cur = 0;
      } else {
        cur += 1;
      }
      ans += (cur - k > 0); 
    }
    cout << ans << '\n';
  }

  return 0;
}


