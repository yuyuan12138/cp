#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, t;
  std::cin >> n >> t;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  auto work = [&]() -> void {
    int max = 0;
    for (int i = 0; i < n; i++) {
      max = std::max(max, a[i]);
    }
    int idx = std::find(a.begin(), a.end(), max) - a.begin();
    a[idx] = 0;
    int rem = max % (n - 1);
    for (int i = 0; i < n; i++) {
      if (idx != i) {
        if (rem >= 1) {
          a[i] += 1;
          rem--;
        }
        a[i] += max / (n - 1);
      }
    }
    std::cout << idx + 1 << '\n';
  };
  for (int i = 0; i < t; i++) {
    work();
  }
  return 0;
}