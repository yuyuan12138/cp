#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n), ans(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    std::vector<int> cnt(n + 1);
    for (int i = 1; i < n; i++) {
      bool ok = false;
      for (int div = 1; div * div <= a[i]; div++) {
        if (a[i] % div == 0) {
          if (cnt[div] == 0 && cnt[a[i] / div] == 0) {
            ok = true;
          }
          cnt[div]++;
          cnt[a[i] / div]++;
        }
      }
      if (ok) {
        ans[i] = i;
      } else {
      }
    }
  }
  return 0;
}
