#include <bits/stdc++.h>

using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    int64_t ans = 0;
    for (int b = 1; b <= m; b++) {
      ans += int64_t(n / b + 1) / b;
    }
    cout << ans - 1 << '\n';
  }

  return 0;
}