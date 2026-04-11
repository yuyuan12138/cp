/**
 *    author:  yuyuan
 *    created: 2025-12-13 18:11:35
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
  vector<array<int, 3>> a(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> a[i][j];
    }
    a[i][2] = i;
  }
  sort(a.begin(), a.end(), [](const auto& a, const auto& b) -> bool {
    if (a[0] == b[0]) {
      if (a[1] == b[1]) {
        return a[2] < b[2];
      }
      return a[1] > b[1];
    }
    return a[0] < b[0];
  });
  
  debug(a);
  set<int> st;

  vector<vector<int>> ans(2, vector<int> (n));

  for (int i = 0; i < n; i++) {
    int l = a[i][0], r = a[i][1], idx = a[i][2];
    if (st.lower_bound(r) != st.end()) {
      ans[0][idx] = 1;
    }
    st.insert(r);
  }

  st.clear();
  for (int i = n - 1; i >= 0; i--) {
    int l = a[i][0], r = a[i][1], idx = a[i][2];
    if (st.upper_bound(r) != st.begin()) {
      ans[1][idx] = 1;
    }
    st.insert(r);
  } 
  swap(ans[0], ans[1]);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cout << ans[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}


