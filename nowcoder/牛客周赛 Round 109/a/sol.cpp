#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int x1, y1, x2, y2;
  std::cin >> x1 >> y1 >> x2 >> y2;
  std::vector<std::pair<int, int>> a = {{x1 - x2, y1 - y2}, {x1, y1}, {x2, y2}};
  bool ok = false;
  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 3; j++) {
      if (a[i].first * a[j].first + a[i].second * a[j].second == 0) {
        ok = true;
      }
    }
  }
  std::cout << (ok ? "Yes" : "No");
  return 0;
}
