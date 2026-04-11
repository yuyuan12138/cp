#include <bits/stdc++.h>

void solve() {
    int n, rk, ck, rd, cd;
    std::cin >> n >> rk >> ck >> rd >> cd;
    int ans = 0;
    if (rd > rk) {
        ans = std::max(ans, rd);
    } else if (rd < rk) {
        ans = std::max(ans, n - rd);
    }
    if (cd > ck) {
        ans = std::max(ans, cd);
    } else if (cd < ck) {
        ans = std::max(ans, n - cd);
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
