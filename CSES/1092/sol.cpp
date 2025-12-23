/**
 *    author:  yuyuan
 *    created: 2025-12-23 09:37:21
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
  int64_t tot = int64_t(n + 1) * n / 2;
  if (tot % 2 == 0) {
    cout << "YES\n";
    set<int> st;
    for (int i = 1; i <= n; i++) {
      st.insert(i);
    }
    int64_t target = tot / 2;
    while (target) {

    }
  } else {
    cout << "NO\n";
  }

  return 0;
}


