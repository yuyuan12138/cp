/**
 *      author:  yuyuan567
 *      created: 2025-09-08 15:59:46
 */
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
      mp[a[i]].push_back(i);
    }
    bool ok = true;
    int cur = 1;
    vector<int> b(n);
    for (auto [key, value] : mp) {
      if (value.size() % key != 0) {
        ok = false;
        break;
      }
      int cnt = 0;
      for (int i : value) {
        b[i] = cur;
        cnt++;
        if (cnt == key) {
          cur++;
          cnt = 0;
        }
      }
    }
    if (!ok) {
      cout << "-1\n";
    } else {
      for (int i = 0; i < n; i++) {
        cout << b[i] << " \n"[i == n - 1];
      }
    }
  }
  return 0;
}
