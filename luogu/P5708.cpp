#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout << std::fixed << std::setprecision(1);
  double a, b, c;
  std::cin >> a >> b >> c;
  double p = (a + b + c) / 2;
  double s = std::sqrt(p * (p - a) * (p - b) * (p - c));
  s = std::round(s * 10) / 10;
  std::cout << s << '\n';
  return 0;
}