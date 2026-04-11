#include <bits/stdc++.h>

void solve() {
    int n, x;
    std::cin >> x >> n;
    int ans = 0;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            if (x / i >= n) {
                ans = std::max(ans, i);
            }
            if (i >= n) {
                ans = std::max(ans, x / i);
            }
        }
    }
    std::cout << ans << '\n';
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
