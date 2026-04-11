#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt;
  std::cin >> tt;
  while (tt--) {
    std::string s;
    std::cin >> s;
    bool ok = false;
    const int n = s.size();
    std::string ans = "";
    if (n == 1 || (n == 2 && s[0] != s[1])) {
      std::cout << -1 << '\n';
    } else {
      for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
          ok = true;
          ans += s[i - 1];
          ans += s[i];
          break;
        }
      }    
      if (ok) {
        std::cout << ans << '\n';
        continue;
      }
      for (int i = 2; i < n; i++) {
        if (s[i] != s[i - 1] && s[i] != s[i - 2] && s[i - 1] != s[i - 2]) {
          ok = true;
          ans += s[i - 2];
          ans += s[i - 1];
          ans += s[i];
          break;
        }
      }
      if (ok) { 
        std::cout << ans << '\n';
      } else {
        std::cout << -1 << '\n';
      }
    }
  }
}
