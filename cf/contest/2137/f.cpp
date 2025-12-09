#include <bits/stdc++.h>

void solve() {
   int n;
   std::cin >> n;
   std::vector<int> a(n), b(n);
   for (int i = 0; i < n; i++) {
        std::cin >> a[i];
   } 
   for (int i = 0; i < n; i++) {
        std::cin >> b[i];
   }
   std::vector<int> pref_max(n + 1);
   for (int i = 0; i < n; i++) {
        pref_max[i + 1] = std::max(pref_max[i], a[i]);
   }
   pref_max.erase(pref_max.begin());
   
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
