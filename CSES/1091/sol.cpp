/**
 *    author:  yuyuan
 *    created: 2025-12-10 21:26:01
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

  int n, m;
  cin >> n >> m;
  multiset<int> st;
  vector<int> t(m);
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    st.insert(x);
  }
  for (int i = 0, x; i < m; i++) {
    cin >> x;
    auto ptr = st.upper_bound(x);
    if (ptr == st.begin()) {
      cout << -1 << '\n';
    } else {
      ptr = prev(ptr);
      cout << *ptr << '\n';
      st.erase(ptr);
    }
  }
  
  return 0;
}


