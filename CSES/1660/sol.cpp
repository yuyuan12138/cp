/**
 *    author:  yuyuan
 *    created: 2025-12-19 16:43:59
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
  int x;
  cin >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  map<int64_t, int> mp;
  int64_t cur = 0;
  int64_t ans = 0;
  mp[0] = 1;
  for (int i = 0; i < n; i++) {
    cur += a[i];
    if (mp.count(cur - x)) {
      ans += mp[cur - x];
    }
    mp[cur]++;
  }
  cout << ans;
  return 0;
}


