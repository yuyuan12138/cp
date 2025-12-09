/**
 *      author:  yuyuan567
 *      created: 2025-09-10 09:02:57
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
    int64_t k, x;
    cin >> k >> x;
    int64_t tot = (1LL << (k + 1));
    vector<int> ans;
    int64_t y = tot - x;

    while (y != x) {
      if (x < y) {
        y -= x;
        x *= 2;
        ans.push_back(1);
      } else {
        x -= y;
        y *= 2;
        ans.push_back(2);
      }
    }
    cout << ans.size() << '\n';
    while (!ans.empty()) {
      cout << ans.back() << " ";
      ans.pop_back();
    }
    cout << "\n";
  }
  return 0;
}
