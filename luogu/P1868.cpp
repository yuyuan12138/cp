#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<std::array<int, 3>> s(n);
  for (int i = 0; i < n; i++) {
    s[i][0] = i;
    std::cin >> s[i][1] >> s[i][2];
  }
  std::sort(s.begin(), s.end(), [](const auto& a, const auto& b) -> bool {
    if (a[2] == b[2]) {
      if (a[1] == b[1]) {
        return a[0] < b[0];
      } else {
        return a[1] < b[1];
      } 
    } else {
      return a[2] < b[2];
    }
  });

  std::vector<int> f(n);
  f[0] = s[0][2] - s[0][1] + 1;
  for (int i = 1; i < n; i++) {
    int lo = 0, hi = i - 1;
    f[i] = f[i - 1];
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (s[mid][2] < s[i][1]) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    if (hi >= 0) {
      f[i] = std::max(f[i], f[hi] + s[i][2] - s[i][1] + 1);
    }
    f[i] = std::max(f[i], s[i][2] - s[i][1] + 1);
  }
  std::cout << f[n - 1];
  return 0;
}
