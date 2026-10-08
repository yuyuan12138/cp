/**
 *    author:  yuyuan
 *    created: 09.09.2026 16:29:09
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

  inline bool is_same(int x, int y) {
    return get(x) == get(y);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  dsu d(2 * n);
  vector<array<int, 3>> s(m);
  for (int i = 0; i < m; i++) {
    cin >> s[i][1] >> s[i][2] >> s[i][0];
    s[i][1]--, s[i][2]--;
  }
  sort(s.begin(), s.end(), greater<>());
  for (int i = 0; i < m; i++) {
    d.unite(s[i][1], s[i][2] + n);
    d.unite(s[i][2], s[i][1] + n);
    if (d.is_same(s[i][1], s[i][1] + n) || d.is_same(s[i][2], s[i][2] + n)) {
      cout << s[i][0];
      return 0;
    }
  }
  cout << 0;
  return 0;
}