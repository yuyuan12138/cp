#include <bits/stdc++.h>

#define int int64_t

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    std::map<int, int> mp;
    for (int i = 0; i < n; i++) {
      mp[a[i]]++;
    }
    int64_t ans = 0;
    int cur = 0;
    for (auto [num, cnt] : mp) {
      if (cnt % 2 == 0) {
        ans += cnt * num;
        cur += cnt;
        mp[num] = 0;
      } else {
        ans += (cnt - 1) * num;
        cur += cnt - 1;
        mp[num] = 1;
      }
    }
    std::vector<int> p;
    for (auto& [num, cnt] : mp) { 
      if (cnt >= 1) {
        p.push_back(num);
      }
    }
    std::sort(p.begin(), p.end());
    if (p.size() == 0) {
      if (cur >= 3) {
        std::cout << ans << '\n';
      } else {
        std::cout << 0 << '\n';
      }
    } else if (p.size() == 1) {
      int mx = p[0];
      if (ans <= mx) {
        if (cur <= 2) {
          std::cout << 0 << '\n';
        } else {
          std::cout << ans << '\n';
        }
      } else {
        std::cout << ans + mx << '\n';
      }
    } else if (p.size() >= 2) {
      const int m = p.size();
      int64_t init = ans;
      bool ok = false;
      for (int i = m - 1; i >= 1; i--) {
        if (p[i - 1] + init > p[i]) {
          ans = std::max(ans, init + p[i - 1] + p[i]);
          ok = true;
        }
      }
      for (int i = 0; i < m; i++) {
        if (p[i] < init) {
          ok = true;
          ans = std::max(ans, init + p[i]);
        } 
      }
      if (!ok && cur <= 2) {
        std::cout << 0 << '\n';
      } else {
        std::cout << ans << '\n';
      }
    }
    
  } 
  return 0;
}