#include <bits/stdc++.h>

void solve() {
   int k;
   std::cin >> k;
   std::string s;
   std::cin >> s;
   int n, m;
   std::cin >> n >> m;
   for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
   }
   int del = m - n + 1;
   del %= k;

   if (s[del] == '1') {
        std::cout << "2\n";
   } else {
        std::cout << "1\n";
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
