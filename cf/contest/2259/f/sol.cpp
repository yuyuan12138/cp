/**
 *    author:  yuyuan
 *    created: 10.09.2026 16:29:39
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
  int tt;
  cin >> tt;
  while (tt--) {
    deque<int> dq;
    int n;
    cin >> n;
    int64_t ans = 0;
    int cnt_zeros = 0;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      dq.push_back(x);
    }
    for (int i = dq.size() - 1; i >= 0; i--) {
      if (dq[i] == 0) {
        cnt_zeros++;
      } else {
        ans += cnt_zeros;
      }
    } 
    cout << ans << ' ';
    string s;
    cin >> s;
    while (!dq.empty() && dq.front() == 0) {
      cnt_zeros--;
      dq.pop_front();
    }
    while (!dq.empty() && dq.back() == 1) {
      dq.pop_back();
    }
    for (int i = 0; i < n; i++) {
      while (!dq.empty() && dq.front() == 0) {
        cnt_zeros--;
        dq.pop_front();
      }
      while (!dq.empty() && dq.back() == 1) {
        dq.pop_back();
      }
      if (dq.empty()) {
        cout << 0 << ' ';
      } else {
        if (s[i] == '0') {
          ans -= dq.size() - cnt_zeros;
          cnt_zeros--;
          dq.pop_back();
        } else {
          ans -= cnt_zeros;
          dq.pop_front();
        } 
        cout << ans << ' ';
      }
    }
    cout << '\n';
  }
  return 0;
}