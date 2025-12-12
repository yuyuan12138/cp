/**
 *    author:  yuyuan
 *    created: 2025-12-12 17:00:03
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
  multiset<int> st;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    auto it = st.upper_bound(x);
    if (it == st.end()) {
      st.insert(x);
    } else {
      st.erase(it);
      st.insert(x);
    }
  }
  cout << st.size();


  return 0;
}

