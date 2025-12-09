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
    std::vector<int> d(n);
    for (int i = 0; i < n; i++) {
      d[i] = std::max(a[i], a[(i + 1) % n]);
    }
    std::sort(d.begin(), d.end());
    int64_t ans = 0;
    for (int i = 0; i < n - 1; i++) {
      ans += d[i];
    }
    std::cout << ans << '\n';
  }
}
