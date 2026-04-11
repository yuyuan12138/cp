/**
 *    author:  yuyuan
 *    created: 24.03.2026 19:06:51
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x, k;
  cin >> n >> x >> k;
  vector<vector<int>> st(1e5 + 1);
  for (int i = 0; i < k; i++) {
    int l;
    cin >> l;
    st[l].push_back(i);
  }
  vector<vector<int>> c(1e5 + 1);
  int m; 
  cin >> m;
  for (int i = 0; i < m; i++) {
    int im, jm;
    cin >> im >> jm;
    c[jm].push_back(im);
  }
  vector<int> ans(k);
  map<int, int> cnt;
  int cur = 0;
  for (int i = 0, j = 0; i < 1e5 + 1; i++) {
    while (j < 1e5 + 1 && j - i + 1 <= x) {
      for (int val : c[j]) {
        cnt[val]++;
        if (cnt[val] == 1) {
          cur++;
        }
      }
      j++;
    }
    for (int val : st[i]) {
      ans[val] = cur;
    }
    for (int val : c[i]) {
      cnt[val]--;
      if (cnt[val] == 0) {
        cur--;
      }
    }
  }
  for (int i = 0; i < k; i++) {
    cout << ans[i] << ' ';
  }
  return 0;
}
