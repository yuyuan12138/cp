#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

bool check(std::string& a, std::string& b, int x, int y, int n, int m) {
  if (n - x < m - y) {
    return false;
  }
  for (int i = 0; (x + i) < n && (y + i) < m; i++) {
    if (a[x + i] != b[y + i]) {
      return false;
    }
  }
  return true;
}

int memo[1001][201][201];

int dfs(std::string& A, std::string& B, int n, int m, int k) {
  if (n == 0 || m == 0 || k == 0) {
    return (k == 0 && m == 0);
  }

  if (memo[x][y][k] != -1) {
     return memo[x][y][k];
  }

  for (int y = m - 1; y >= 0; y--) {
    for (int x = n - 1; x >= 0; x--) {
      if (check(A, B, x, y, n, m)) {
        ans += dfs(A, B, x, y, k - 1) % MOD;
        ans %= MOD;
      }
    }
  }
  memo[n][m][k] = ans;
  return ans;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  memset(memo, -1, sizeof(memo));
  int n, m, k;
  std::cin >> n >> m >> k;
  std::string A, B;
  std::cin >> A >> B;
  int ans = dfs(A, B, n, m, k);
  std::cout << ans % MOD;
}
