#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  std::vector<std::array<int, 2>> pref(n + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      pref[i + 1][j] = pref[i][j];
    }
    if (s[i] == '0') {
      pref[i + 1][0]++;
    } else {
      pref[i + 1][1]++;
    }
  }
  int ans = INT32_MAX;
  for (int i = 0, j = 0; i < n; i++) {
    while (j < n && s[i] == s[j]) {
      j++;
    }
    int digit = s[i] - '0';
    int same = pref[i][digit] * 2 + (pref[n][digit] - pref[j][digit]) * 2;
    int nsame = pref[i][digit ^ 1] + pref[n][digit ^ 1] - pref[j][digit ^ 1];
    ans = std::min(ans, same + nsame);
  }
  std::cout << ans << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }   
  return 0;
}