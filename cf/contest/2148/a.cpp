#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt;
  std::cin >> tt;
  while (tt--) {
    int x, n;
    std::cin >> x >> n;
    int flag = 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += flag * x;
      flag *= -1;
    }
    std::cout << sum << '\n';
  }
  return 0;
}