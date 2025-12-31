/**
 *    author:  yuyuan
 *    created: 2025-12-09 21:31:38
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
    vector<int> freqs(2 * n);
    for (int i = 0, x; i < 2 * n; i++) {
      cin >> x;
      x--;
      freqs[x]++;
    }
    int cnt = 0, ans = 0;
    bool ok = false;
    for (int x = 0; x < 2 * n; x++) {
      if (freqs[x] == 0) {
        continue;
      }
      if (freqs[x] % 2 == 1) {
        ans += 1;
        ok = true;
      } else if (freqs[x] % 4 == 0) {
        ans += 2;
        cnt++;
      } else {
        ans += 2;
      }
    }
    if (cnt % 2 != 0 && !ok) {
      ans -= 2;
    }
    cout << ans << '\n';
  }

  return 0;
}


