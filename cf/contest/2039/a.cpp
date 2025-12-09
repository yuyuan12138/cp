#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cout << i + i - 1 << " \n"[i == n];
    }
  }
}
