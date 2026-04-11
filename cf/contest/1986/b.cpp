#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> s(n, std::vector<int> (m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        std::cin >> s[i][j];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        bool ok = true;
        int mx = 0;
        if (i > 0) {
          mx = std::max(mx, s[i - 1][j]);
          if (s[i - 1][j] >= s[i][j]) {
            ok = false;
          }
        } 
        if (i < n - 1) {
          mx = std::max(mx, s[i + 1][j]);
          if (s[i + 1][j] >= s[i][j]) {
            ok = false;
          }
        }
        if (j > 0) {
          mx = std::max(mx, s[i][j - 1]);
          if (s[i][j - 1] >= s[i][j]) {
            ok = false;
          }
        }
        if (j < m - 1) {
          mx = std::max(mx, s[i][j + 1]);
          if (s[i][j + 1] >= s[i][j]) {
            ok = false;
          }
        }
        if (ok) {
          s[i][j] = mx;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        std::cout << s[i][j] << " ";
      }
      std::cout << '\n';
    }
  } 
  return 0;
}