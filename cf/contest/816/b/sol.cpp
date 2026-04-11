#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int m, k, q;
  std::cin >> m >> k >> q;
  const int n = 200000;
  std::vector<int64_t> a(n + 1);
  for (int i = 0; i < m; i++) {
    int l, r;
    std::cin >> l >> r;
    a[l - 1] += 1;
    a[r] -= 1;
  }
  a.pop_back();
  for (int i = 1; i < n; i++) {
    a[i] = a[i - 1] + a[i];
  }
  for (int i = 0; i < n; i++) {
    if (a[i] >= k) {
      a[i] = 1;
    } else {
      a[i] = 0;
    }
  }
  for (int i = 1; i < n; i++) {
    a[i] += a[i - 1];
  }
  for (int i = 0; i < q; i++) {
    int l, r;
    std::cin >> l >> r;
    l--, r--;
    if (l == 0) {
      std::cout << a[r] << '\n';
    } else {
      std::cout << a[r] - a[l - 1] << '\n';
    }
  }
  return 0;
}
