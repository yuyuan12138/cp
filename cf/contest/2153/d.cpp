#include <bits/stdc++.h>

constexpr int64_t inf = 1e18;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<int> a(2 * n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      // std::cout << i << ' ' << a[i] << std::endl;
      a[i + n] = a[i];
    }
      for (int i = 0; i < 2 * n; i++) {
        std::cerr << a[i] << ' ';
      }
      std::cerr << '\n';
    int64_t ans = inf;
    auto get = [](int64_t a, int64_t b, int64_t c) -> int64_t {
      int64_t max = std::max({a, b, c});
      int64_t min = std::min({a, b, c});
      return max - min;
    };
    auto work = [&]() -> void {
      std::vector<int64_t> f(n, inf);
      f[0] = inf;
      f[1] = int64_t(std::abs(a[0] - a[1]));
      f[2] = get(a[0], a[1], a[2]);
      for (int i = 3; i < n; i++) {
        f[i] = std::min(f[i], f[i - 3] + get(a[i], a[i - 1], a[i - 2]));
        f[i] = std::min(f[i], f[i - 2] + (int64_t)std::abs(a[i] - a[i - 1]));
      }
      ans = std::min(ans, f[n - 1]);


      for (int i = 1; i < 2 * n; i++) {
        a[i - 1] = a[i];
      }
    };
    for (int i = 0; i < 3; i++) {
      work();
    }
    std::cout << ans << '\n';
  }
  return 0;
}