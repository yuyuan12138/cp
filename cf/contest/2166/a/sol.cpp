#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::string s;
    std::cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] != s[n - 1]) {
        ans++;
      }
    }
    std::cout << ans << '\n';
  }
}
