/**
 *    author:  yuyuan
 *    created: 24.03.2026 12:58:12
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  int64_t tot = int64_t(1 + n) * n / 2;
  if (tot % 2 != 0) {
    cout << "NO";
  } else {
    cout << "YES\n";
    vector<bool> vis(n + 1, 0);
    int64_t sum1 = 0;
    set<int> st;
    for (int i = 1; i <= n; i++) {
      st.insert(i);
    }
    int cnt = 0;
    while (sum1 < tot / 2) {
      int64_t remaining = tot / 2 - sum1;
      debug(remaining);
      debug(st);
      auto it = st.upper_bound(remaining);
      if (it == st.begin()) {
        break;
      }
      it = prev(it);
      int num = *it;

      debug(num);
      vis[num] = true;
      sum1 += num;
      cnt++;
      st.erase(st.find(num));
    }
    cout << cnt << '\n';
    for (int i = 1; i <= n; i++) {
      if (vis[i]) cout << i << " \n"[i == n];
    }
    cout << n - cnt << '\n';
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) cout << i << " \n"[i == n];
    }
  }

  return 0;
}
