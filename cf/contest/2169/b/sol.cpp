#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt;
  std::cin >> tt;
  while (tt--) {
    std::string s;
    std::cin >> s;
    const int n = s.size();
    if (n == 1) {
      std::cout << 1 << '\n';
    } else {
      bool ok = false;
      for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
          if (i > 0 && s[i - 1] == '>' || s[i - 1] == '*') {
            ok = true;
          }
          if (i < n - 1 && s[i + 1] == '<' || s[i + 1] == '*') {
            ok = true;
          }
        }
      }
      for (int i = 1; i < n; i++) {
        if (s[i - 1] == '>' && s[i] == '<') {
          ok = true;
        }
      }
      if (ok) {
        std::cout << -1 << '\n';
      } else {
        int cnt = 0;
        int cnt2 = 0;
        int cnt3 = 0;
        for (int i = 0; i < n; i++) {
          if (s[i] == '<') {
            cnt++;
          }
          if (s[i] == '>') {
            cnt3++;
          }
          if (s[i] == '*') {
            cnt2++;
          }
        }
        std::cout << cnt2 + std::max(cnt3, cnt) << '\n';
      }
    }
  }
}
