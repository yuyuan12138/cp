/**
 *    author:  yuyuan
 *    created: 24.03.2026 11:48:56
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
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
    if (n % 2 == 1) {
      if (s[0] != 'a' && s[0] != '?') {
        cout << "NO\n";
      } else {
        bool ok = true;
        for (int i = 2; i < n; i += 2) {
          if (s[i] == s[i - 1] && s[i] != '?' && s[i - 1] != '?') {
            ok = false;
          }
        }
        cout << (ok ? "YES\n" : "NO\n");
      }
    } else {
      bool ok = true;
      for (int i = 1; i < n; i += 2) {
        if (s[i] == s[i - 1] && s[i] != '?' && s[i - 1] != '?') {
          ok = false;
        }
      }
      cout << (ok ? "YES\n" : "NO\n");
    }
  }
  return 0;
}
