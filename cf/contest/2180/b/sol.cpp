/**
 *    author:  yuyuan
 *    created: 2025-12-20 17:02:59
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
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    string ans = "";
    for (int i = 0; i < n; i++) {  
      ans = min(ans + s[i], s[i] + ans);
    }
    cout << ans << '\n';
  }

  return 0;
}

