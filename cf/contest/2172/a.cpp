#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::vector<int> a(3);
  for (int i = 0; i < 3; i++) {
    std::cin >> a[i];
  }
  std::vector<int> idx(3);
  std::iota(idx.begin(), idx.end(), 0);
  std::sort(idx.begin(), idx.end(), [&](const int x, const int y) -> bool {
        if (a[x] == a[y]) {
          return x < y;
        } else {
          return a[x] < a[y];
        }
      });
  if (a[idx[2]] - a[idx[0]] >= 10) {
    std::cout << "check again";
  } else {
    std::cout << "final " << a[idx[1]];
  }
  return 0;
}
