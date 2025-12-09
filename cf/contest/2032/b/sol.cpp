#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, k;
    std::cin >> n >> k;
    if (n == 1) {
      std::cout << 1 << '\n';
      std::cout << 1 << '\n';
    } else {
      if (k == 1 || k == n) {
        std::cout << -1 << '\n';
      } else {
        std::cout << 3 << '\n';
        if (k % 2 == 0) {
          std::cout << 1 << ' ' << k << ' ' << k + 1 << '\n';
        } else {
          std::cout << 1 << ' ' << k - 1 << ' ' << k + 2 << '\n';
        }
      }
    }
  }
  return 0;
}
