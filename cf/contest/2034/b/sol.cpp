#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, m, k;
    std::cin >> n >> m >> k;
    int ans = 0;
    std::string s;
    std::cin >> s;
    int cur = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0' && cur == m - 1) {
        ans++;
        cur = 0;
        for (int j = i; j < std::min(n, i + k); j++) {
          s[j] = '1';
        }
      } else if (s[i] == '0') {
        cur++;
      } else {
        cur = 0;
      }
    }
    std::cout << ans << '\n';
  }
}
