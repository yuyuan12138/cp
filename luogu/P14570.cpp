#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  if (m % 2 == 0) {
    m -= 1;
  }
  for (int x = m, i = 0; i < n; x -= 2, i++) {
    std::cout << x << " ";
  }

  return 0;
}
