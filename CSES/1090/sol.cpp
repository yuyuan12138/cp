/**
 *    author:  yuyuan
 *    created: 2025-12-10 16:47:26
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
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  sort(p.begin(), p.end());
  int ans = 0;
  for (int i = n - 1, j = 0; i >= j; i--) {
    if (p[i] + p[j] <= x) {
      j++;
    }
    ans++;
  }
  cout << ans;
  return 0;
}

