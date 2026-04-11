#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<std::array<int, 2>> s(n);
  for (int i = 0; i < n; i++) {
    std::cin >> s[i][0] >> s[i][1];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if ((s[i][0] - s[j][0]) * (s[i][0] - s[j][0]) +
              (s[i][1] - s[j][1]) * (s[i][1] - s[j][1]) ==
          1) {
        ans++;
      }
    }
  }
  std::cout << ans;
  return 0;
}
