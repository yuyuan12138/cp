/**
 *    author:  yuyuan
 *    created: 2025-12-10 16:03:10
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
  
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
   
  sort(x.begin(), x.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0 || x[i] != x[i - 1]) {
      ans++;
    }
  }
  cout << ans;
  return 0;
}

