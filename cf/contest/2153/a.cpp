#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    int sum = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] != cur) {
        cur = a[i];
        sum += 1;
      }
    }
    std::cout << sum << '\n';
  }
  return 0;
}