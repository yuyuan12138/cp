#include <bits/stdc++.h>

void solve() {
     int n;
     std::cin >> n;
     std::vector<int> a(n);
     int64_t sum = 1;
     int cnt0 = 0;
     for (int i = 0; i < n; i++) {
          std::cin >> a[i];
          if (a[i] != 0) {
               sum *= 1ll * a[i];
          } else {
               cnt0++;
          }
     }
     int64_t mx = 0;
     if (cnt0 == 0) {
          for (int i = 0; i < n; i++) {
               mx = std::max(sum / a[i] * (a[i] + 1), mx);
          }
          std::cout << mx << '\n';
     } else if (cnt0 == 1) {
          std::cout << sum << '\n';
     } else {
          std::cout << 0 << '\n';
     }
     
     
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
