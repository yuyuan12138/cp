/**
 *    author:  yuyuan
 *    created: 2025-12-19 16:39:41
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
  vector<int> a(n);
  stack<int> st;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    while (!st.empty() && a[st.top()] >= a[i]) {
      st.pop();
    }
    if (!st.empty()) {
      ans[i] = st.top() + 1;
    }
    st.push(i);
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }

  return 0;
}


