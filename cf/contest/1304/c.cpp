#include <bits/stdc++.h>

constexpr int inf = 1e9;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> t(n), l(n), h(n);
    for (int i = 0; i < n; i++) {
      std::cin >> t[i] >> l[i] >> h[i];
    }

    int cur_min = m, cur_max = m;
    int cur_t = 0;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      int dist = t[i] - cur_t;
      cur_min -= dist;
      cur_max += dist;
      if (cur_min > h[i] || cur_max < l[i]) {
        ok = false;
      }
      cur_min = std::max(cur_min, l[i]);
      cur_max = std::min(cur_max, h[i]);
      cur_t = t[i];
    }
    std::cout << (ok ? "YES\n" : "NO\n");
  } 
  return 0;
}