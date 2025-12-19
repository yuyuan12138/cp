/**
 *    author:  yuyuan
 *    created: 2025-12-19 15:25:32
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

  int n, x;
  cin >> n >> x;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  array<int, 3> ans = {-1, -1, -1};
  for (int i = 0; i < n; i++) {
    int target = x - a[i].first;
    int l = i + 1, r = n - 1;
    while (l < r) {
      if (a[l].first + a[r].first < target) {
        l++;
      } else if (a[l].first + a[r].first > target) {
        r--;
      } else {
        ans[0] = a[i].second;
        ans[1] = a[l].second;
        ans[2] = a[r].second;
        break;
      }
    }
  }
  if (ans[0] == -1) {
    cout << "IMPOSSIBLE";
  } else {
    cout << ans[0] + 1 << " " << ans[1] + 1 << " " << ans[2] + 1;
  }
  return 0;
}


