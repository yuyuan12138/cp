/**
 *    author:  yuyuan
 *    created: 2025-12-19 16:55:23
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

  int n, k;
  cin >> n >> k;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  int cur = 0;
  map<int, int> mp;
  int64_t ans = 0;
  for (int i = 0, j = 0; i < n; i++) {
    while (j < n && cur <= k) {
      if (mp[x[j]] == 0) {
        if (cur == k) {
          break;
        } else {
          cur++;
        }
      }
      mp[x[j]]++;
      j++;
    }
    ans += j - i;
    if (mp[x[i]] == 1) {
      cur--;
    }
    mp[x[i]]--;
  }
  cout << ans;

  return 0;
}


