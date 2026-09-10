/**
*    author:  yuyuan
*    created: 09.09.2026 15:26:30
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

class dsu {
 public:
  vector<int> p;
  int n;
  
  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, h, r;
    cin >> n >> h >> r;
    dsu d(n);
    vector<int64_t> x(n), y(n), z(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i] >> z[i];
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if ((int64_t) (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) + (z[i] - z[j]) * (z[i] - z[j]) <= int64_t(4) * r * r) {
          d.unite(i, j);
        }
      }
    }
    bool ok = false;
    for (int i = 0; i < n; i++) {
      if (h - z[i] <= r) {
        for (int j = 0; j < n; j++) {
          if (z[j] <= r && d.get(i) == d.get(j)) {
            ok = true;
          } 
        }
      }
    }
    cout << (ok ? "Yes\n" : "No\n");
  }
  return 0;
}