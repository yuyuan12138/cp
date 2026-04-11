#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int tt;
  std::cin >> tt;
  while (tt--) {
    int x, y, a, b;
    std::cin >> x >> y >> a >> b;
    int dis = y - x;
    if ((y - x) % (a + b) == 0) {
      std::cout << (y - x) / (a + b) << '\n';
    } else {
      std::cout << -1 << '\n';
    }
  }

  return 0;
}