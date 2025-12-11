/**
 *    author:  yuyuan
 *    created: 2025-12-11 18:25:08
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

  int n;
  cin >> n;
  map<int, int> mp;
  int x;
  cin >> x;
  int ans1 = -1, ans2 = -1;
  for (int i = 0, s; i < n; i++) {
    cin >> s;
    if (mp.count(x - s)) {
      ans1 = i;
      ans2 = mp[x - s];
    }
    mp[s] = i;
  }
  if (ans1 != -1) {
    cout << ans1 + 1 << ' ' << ans2 + 1;
  } else {
    cout << "IMPOSSIBLE";
  }


  return 0;
}

