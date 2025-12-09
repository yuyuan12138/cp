#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, a;
    std::cin >> n >> a;
    std::vector<int> v(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      std::cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
      if (v[i] < a) {
        ans++;
      }
    }
    if (ans * 2 >= n) {
      std::cout << a - 1 << '\n';
    } else {
      std::cout << a + 1 << '\n';
    }
  }
}
