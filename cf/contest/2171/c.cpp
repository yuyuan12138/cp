#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    int x = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        x ^= a[i];
    }    
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        x ^= b[i];
    }
    int idx = -1;
    for (int bit = 30; bit >= 0; bit--) {
        if (x & (1 << bit)) {
            idx = bit;
            break;
        }
    }
    if (idx == -1) {
        std::cout << "Tie" << '\n';
    } else {
        std::string ans = "Tie";
        for (int i = n - 1; i >= 0; i--) {
            if ((a[i] & (1 << idx)) != (b[i] & (1 << idx))) {
                if (i % 2 == 0) {
                    ans = "Ajisai";
                } else {
                    ans = "Mai";
                }
                break;
            }
        }
        std::cout << ans << '\n';
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
}
