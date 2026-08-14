#include <bits/stdc++.h>

void solve() {
    int x;
    std::cin >> x;
    int ans = 1;
    while (x) {
        x /= 10;
        ans *= 10;
    }
    std::cout << ans + 1 << '\n';
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
