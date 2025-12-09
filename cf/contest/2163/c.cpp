#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1e9;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> s(2, std::vector<int> (n));
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        std::cin >> s[i][j];
      }
    }
    std::vector<int> ans(2 * n + 1, inf);
    std::vector<std::vector<int>> up(2, std::vector<int> (n + 1));
    std::vector<std::vector<int>> down(2, std::vector<int> (n + 1));
    up[1][0] = inf;
    down[1][n] = inf;
    for (int i = 0; i < n; i++) {
      up[0][i + 1] = std::max(up[0][i], s[0][i]);
      up[1][i + 1] = std::min(up[1][i], s[0][i]);
    }
    for (int i = n - 1; i >= 0; i--) {
      down[0][i] = std::max(down[0][i + 1], s[1][i]);
      down[1][i] = std::min(down[1][i + 1], s[1][i]);
    }
    for (int i = 0; i < n; i++) {
      int max_up = up[0][i + 1], min_up = up[1][i + 1];
      int max_down = down[0][i], min_down = down[1][i];
      int min = std::min(min_down, min_up);
      int max = std::max(max_down, max_up);
      ans[min] = std::min(ans[min], max);
    }
    i64 tot = 0;
    for (int i = 2 * n - 1; i >= 1; i--) {
      ans[i] = std::min(ans[i], ans[i + 1]);
    }
    for (int i = 1; i <= 2 * n; i++) {
      if (ans[i] != inf) {
        tot += 2 * n - ans[i] + 1;
      }
    }
    std::cout << tot << '\n';
  }
  return 0;
}

