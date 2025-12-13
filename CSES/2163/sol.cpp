/**
 *    author:  yuyuan
 *    created: 2025-12-12 21:56:13
 **/
#include <bits/stdc++.h>
#include <ext/rope>
using namespace __gnu_cxx;

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
  if (n == 1) {
    cout << 1;
    return 0;
  }
  rope<int> a;
  for (int i = 1; i <= n; i++) {
    a.push_back(i);
  }

  int cur = k % int(a.size());
  while (a.size() > 0) {
    cout << a[cur] << ' ';
    a.erase(cur, 1);
    if (a.size() > 0) {
      cur = (cur + k) % int(a.size());
    }
  }
  
  return 0;
}


