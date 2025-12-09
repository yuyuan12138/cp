/**
 *      author:  yuyuan567
 *      created: 2025-09-11 09:40:03
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
  int a = s[0] - '0';
  int b = s[2] - '0';
  if (b == 8) {
    cout << a + 1 << "-" << 1 << '\n';
  } else {
    cout << a << "-" << b + 1 << '\n';
  }
  return 0;
}
