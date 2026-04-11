/**
 *    author:  yuyuan
 *    created: 2025-12-13 18:11:35
 **/
#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
template <typename T, typename C = std::less<>>
using ordered_set =
    __gnu_pbds::tree<T, __gnu_pbds::null_type, C, __gnu_pbds::rb_tree_tag,
                     __gnu_pbds::tree_order_statistics_node_update>;

// less_equal<int>
// order_of_key(num), find_by_order(key)

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
  
  ordered_set<int, less_equal<int>> st;

  vector<vector<int>> ans(2, vector<int> (n));
  // order_of_key(num)
  for (int i = 0; i < n; i++) {
    int r = a[i][1], idx = a[i][2];
    int rank = st.order_of_key(r);
    ans[0][idx] = (int) st.size() - rank;
    st.insert(r);
  }

  st.clear();
  for (int i = n - 1; i >= 0; i--) {
    int r = a[i][1], idx = a[i][2];
    int rank = st.order_of_key(r + 1);
    ans[1][idx] = rank;
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


