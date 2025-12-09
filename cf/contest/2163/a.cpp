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
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (i % 2 && i < n - 1 && a[i] != a[i + 1]) {
        ok = false;
      }
    }
    std::cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}
