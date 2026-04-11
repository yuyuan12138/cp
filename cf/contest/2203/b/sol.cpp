/**
 *    author:  yuyuan
 *    created: 26.03.2026 20:01:13
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int64_t n;
    cin >> n;
    vector<int> cnt(10);
    int first = 0;
    int sum = 0;
    while (n) {
      cnt[n % 10]++;
      sum += n % 10;
      if (n >= 1 && n <= 9) {
        first = n;
      }
      n /= 10;
    }
    int ans = 0;
    for (int x = 9; x >= 1; x--) {
      if (sum < 10) {
        break;
      }
      if (x == first) {
        while (sum >= 10 && cnt[x] >= 2) {
          ans++;
          cnt[x]--;
          sum -= x;
        }
        if (sum >= 10) {
          sum -= x - 1;
          ans++;
        }
      } else {
        while (sum >= 10 && cnt[x] >= 1) {
          ans++;
          cnt[x]--;
          sum -= x;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
