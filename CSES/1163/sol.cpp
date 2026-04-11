/**
 *    author:  yuyuan
 *    created: 2025-12-12 17:13:29
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

  int x, n;
  set<int> st;
  multiset<int> cur;
  cin >> x >> n;
  st.insert(0);
  st.insert(x);
  cur.insert(x);
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    auto it = st.lower_bound(x);
    int r = *it - x;
    int l = x - *prev(it);
    int del = *it - *prev(it);
    cur.erase(cur.find(del));
    cur.insert(r);
    cur.insert(l);
    st.insert(x);
    cout << *prev(cur.end()) << " \n"[i == n - 1];
  } 

  return 0;
}

