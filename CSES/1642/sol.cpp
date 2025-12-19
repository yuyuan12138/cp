/**
 *    author:  yuyuan
 *    created: 2025-12-19 16:04:37
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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n <= 3) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  map<int, pair<int, int>> mp;
  array<int, 4> ans = {-1, -1, -1, -1};
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int target = x - a[i] - a[j];
      if (mp.count(target)) {
        ans[0] = i; ans[1] = j; ans[2] = mp[target].first; ans[3] = mp[target].second;
      }
    }
    for (int j = 0; j <= i; j++) {
      mp[a[i] + a[j]] = {i, j};
    }
  }
  if (ans[0] != -1) {
    cout << ans[0] + 1 << ' ' << ans[1] + 1 << ' ' << ans[2] + 1 << ' ' << ans[3] + 1;
  } else {
    cout << "IMPOSSIBLE";
  }

    

  return 0;
}


