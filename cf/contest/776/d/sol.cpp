/**
 *    author:  yuyuan
 *    created: 09.09.2026 17:48:24
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

class DisjointSetUnion {
 public:
  vector<int> p;
  int n;

  DisjointSetUnion(int _n) : n(_n) {
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

  inline bool is_same(int x, int y) {
    return get(x) == get(y);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> r(n);
  vector<vector<int>> k(n);
  DisjointSetUnion dsu(2 * m);
  for (int i = 0; i < n; i++) {
    cin >> r[i];
  }
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    for (int j = 0; j < x; j++) {
      int door;
      cin >> door;
      door--; 
      k[door].push_back(i);
    }
  }
  for (int i = 0; i < n; i++) {
    if (r[i]) {
      dsu.unite(k[i][0], k[i][1]);
      dsu.unite(k[i][0] + m, k[i][1] + m);
    } else {
      dsu.unite(k[i][0] + m, k[i][1]);
      dsu.unite(k[i][0], k[i][1] + m);
    }
  }
  bool ok = true;
  for (int i = 0; i < m; i++) {
    if (dsu.is_same(i, i + m)) {
      ok = false;
    }
  }
  cout << (ok ? "YES\n" : "NO\n");
  return 0;
}