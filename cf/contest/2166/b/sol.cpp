#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt;
  std::cin >> tt;
  while (tt--) {
    int a, b, n;
    std::cin >> a >> b >> n;
    if (b >= a || int64_t(b) * n <= a) {
      std::cout << 1 << '\n';
    } else {
      std::cout << 2 << '\n';
    }
  }
  return 0;
}
