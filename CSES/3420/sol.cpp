/**
 *    author:  yuyuan
 *    created: 2025-12-12 18:24:36
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
  int64_t ans = 0;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  set<int> st;
  for (int i = 0, j = 0; i < n; i++) {
    while (j < n && !st.contains(x[j])) {
      st.insert(x[j]);
      j++;
    }
    ans += j - i;
    st.erase(st.find(x[i]));
  }
  cout << ans;

  return 0;
}


