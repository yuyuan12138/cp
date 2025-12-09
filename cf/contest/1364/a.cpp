#include <bits/stdc++.h>

void solve() {
  int n, x;
  std::cin >> n >> x;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::vector<int> pref(n + 1);
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + a[i];
  }
  if (x == 1) {
    std::cout << -1 << '\n';
  } else {
    std::vector<std::vector<int>> pos(1e4 + 5);
    for (int i = 1; i <= n; i++) {
      pos[pref[i] % x].push_back(i);
    }
    int ans = 0;
    for (int p : pos[0]) {
      ans = std::max(ans, p);
    }
    
  }
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