#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int64_t x1, y1, x2, y2;
  std::cin >> x1 >> y1 >> x2 >> y2;
  if (y1 != y2 && x1 != x2) {
    std::cout << x1 + 2 << " " << y1;
  } else if (x1 == x2) {
    std::cout << x1 + 2 << " " << y1;
  } else {
    std::cout << x1 << " " << y1 + 2;
  }
  return 0;
}
