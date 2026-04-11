/**
 *    author:  yuyuan
 *    created: 2025-12-14 15:17:26
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
    int n, k;
    cin >> n >> k;
    set<int> a;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      a.insert(x);
    }
    if (a.contains(1)) {
      if ((int) a.size() == k) {
        cout << 1 << '\n' << 1 << '\n';
      } else {
        cout << -1 << '\n';
      }
    } else {
      set<int> b;
      bool ok = true;
      set<int> vis;
      for (int x : a) {
        if (!vis.contains(x)) {
          b.insert(x);
        }
        for (int i = 1; i * x <= k; i++) {
          if (!a.contains(i * x)) {
            ok = false;
          } else {
            vis.insert(i * x);
          }
        }
      }
      if (ok) {
        cout << b.size() << '\n';
        for (int x : b) {
          cout << x << ' ';
        }
        cout << '\n';
      } else {
        cout << -1 << '\n';
      }
    }
  }

  return 0;
}


