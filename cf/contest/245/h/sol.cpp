#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::string s;
  std::cin >> s;
  const int n = s.size();
  std::vector f(n, std::vector<int>(n));
  for (int i = 0; i < n; i++) {
    f[i][i] = 1;
  }
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) {
      f[i][i + 1] = 3;
    } else {
      f[i][i + 1] = 2;
    }
  }
  std::vector is_pa(n, std::vector<int>(n));
  for (int i = 0; i < n; i++) {
    is_pa[i][i] = 1;
  }
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) {
      is_pa[i][i + 1] = 1;
    }
  }
  for (int len = 3; len <= n; len++) {
    for (int l = 0; l + len - 1 < n; l++) {
      int r = l + len - 1;
      is_pa[l][r] = (s[l] == s[r] && is_pa[l + 1][r - 1]);
    }
  }

  for (int len = 3; len <= n; len++) {
    for (int l = 0; l + len - 1 < n; l++) {
      int r = l + len - 1;
      f[l][r] = f[l][r - 1] + f[l + 1][r] - f[l + 1][r - 1] + is_pa[l][r];
    }
  }
  int q;
  std::cin >> q;
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    l--, r--;
    std::cout << f[l][r] << '\n';
  }
  return 0;
}
