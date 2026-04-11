/**
 *    author:  yuyuan
 *    created: 2025-12-19 15:10:59
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
  int64_t tot = accumulate(a.begin(), a.end(), 0LL);
  if (tot - a.back() <= a.back()) {
    cout << 2 * a.back();
  } else {
    cout << tot;
  }

  return 0;
}


