#include <bits/stdc++.h>

using i64 = long long;

void solve() {
   int n;
   std::cin >> n;
   int cnt = 0;
   while (n && (n & 1) == 0) {
        n >>= 1;
   }
   if (n == 1) {
        std::cout << "NO\n";
        return ;
   }
   int x = n;
   std::vector<int> bits;
   while (x) {
        bits.push_back(x & 1);
        x >>= 1;
   }
   const int m = bits.size();
   std::vector<int> vis(m, -1);
   // 0: 01. 1: 11;
   for (int i = 0; i < m; i++) {
        if (bits[i] == 1) {
            vis[i] = 0;
        } else {
            vis[i] = 1;
        }
   }
   int l = 0, r = m - 1;
   bool ok = true;
   while (l < r) {
        if (vis[l] != vis[r]) {
            ok = false;
        }
        l++, r--;
   }
   if (m % 2 == 1 && vis[m / 2] == 0) {
        ok = false;
   }
   std::cout << (ok ? "YES\n" : "NO\n");
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
