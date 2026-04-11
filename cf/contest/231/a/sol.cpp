/**
 *      author:  yuyuan567
 *      created: 2025-09-02 09:31:01
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
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b + c >= 2) {
      ans++;
    }
  }
  cout << ans;
  return 0;
}
