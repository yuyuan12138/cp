/**
 *    author:  yuyuan
 *    created: 2025-12-11 17:55:44
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
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].second >> a[i].first;
  }
  sort(a.begin(), a.end());

  int cur = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (cur <= a[i].second) {
      ans++;
      cur = a[i].first;
    }
  }
  cout << ans;

  return 0;
}

