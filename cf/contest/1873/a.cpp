#include <bits/stdc++.h>

void solve() {
     std::string s;
     std::cin >> s;
     if (s[0] == 'a' || s[1] == 'b' || s[2] == 'c') {
          std::cout << "YES\n";
     } else {
          std::cout << "NO\n";
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
