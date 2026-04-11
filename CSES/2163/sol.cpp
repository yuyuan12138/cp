/**
 *    author:  yuyuan
 *    created: 2025-12-12 21:56:13
 **/
#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

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
  ordered_set st;
  for (int i = 1; i <= n; i++) {
    st.insert(i);
  }
  
  int cur = k % int(st.size());
  while (st.size() > 0) {
    auto it = st.find_by_order(cur);
    cout << *it << ' ';
    st.erase(it);
    if (st.size() > 0) {
      cur = (cur + k) % int(st.size());
    }
  }
  cout << '\n';
  
  return 0;
}


