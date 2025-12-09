#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int64_t n, a, b, c;
  std::cin >> n >> a >> b >> c;
  
  while (b--) {
    n = (n + 1) / 2;
  }
  while (a--) {
    n = n / 2;
  }
  
  while (c--) {
    if (n > 0)
      n = (n - 1) / 2;
  }
  
  std::cout << n << '\n';
  return 0;
}