#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt;
  std::cin >> tt;
  while (tt--) {
    std::string a, b;
    std::cin >> a >> b;
    int n = std::min(a.size(), b.size());
    int ans = 0;
    int cur = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i]) {
        ans++;
        cur = i;
      } else {
        break;
      }
    }
    ans += int(a.size()) - cur - 1 + b.size() - cur;
    if (cur == -1) {
      std::cout << a.size() + b.size() << '\n';
    } else {
      std::cout << ans << '\n';
    }
  }
  return 0;
}
