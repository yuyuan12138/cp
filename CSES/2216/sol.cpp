/**
 *    author:  yuyuan
 *    created: 2025-12-12 11:11:04
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
  vector<int> pos(n);
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    x--;
    pos[x] = i;
  }

  int ans = 1;
  int cur = -1;
  for (int x = 0; x < n; x++) {
    if (cur > pos[x]) {
      ans++;
    }
    cur = pos[x];
  }
  cout << ans;

  return 0;
}


