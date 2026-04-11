/**
 *    author:  yuyuan
 *    created: 2025-12-11 22:11:25
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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int val = a[n / 2];
  int64_t ans = 0;
  for (int i = 0; i < n; i++) {
    ans += abs(a[i] - val);
  }
  cout << ans;

  return 0;
}


