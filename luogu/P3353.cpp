#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  
  int n, w;
  std::cin >> n >> w;
  std::vector<int> b(1e5 + 1);
  for (int i = 0; i < n; i++) {
    int x, bi;
    std::cin >> x >> bi;
    b[x] += bi;
  }
  i64 ans = 0;
  i64 cnt = 0;
  for (int i = 0, j = 0; i <= 1e5; i++) {
    while (j <= 1e5 && j - i + 1 <= w) {
      cnt += b[j];
      j++;
    }
    ans = std::max(ans, cnt);
    cnt -= b[i];
  }
  std::cout << ans << '\n';
  

  return 0;
}