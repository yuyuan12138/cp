#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector<int64_t> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    a[i] = std::max(a[i - 1] - m, a[i]);
  }
  for (int i = n - 2; i >= 0; i--) {
    a[i] = std::max(a[i + 1] - m, a[i]);
  }
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << " \n"[i == n - 1];
  }
  return 0;
}
