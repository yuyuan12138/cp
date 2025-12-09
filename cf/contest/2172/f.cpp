#include <bits/stdc++.h>

constexpr int inf = 1e9;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> p(n);
  for (int i = 0; i < n; i++) {
    std::cin >> p[i];
  }
  std::vector<int> f(n, inf);
  int ans = 0;
  for (int i = 1; i < n; i++) {
    int min = inf;
    int idx = -1;
    for (int j = 0; j < i; j++) {
      if (std::gcd(p[i], p[j]) < min) {
        min = std::gcd(p[i], p[j]);
        idx = j;
      }
    }
    ans += min;
  }
  std::cout << ans;
  return 0;
}
