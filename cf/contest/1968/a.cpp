#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int x;
    std::cin >> x;
    int val = 0;
    int ans = 0;
    for (int y = 1; y < x; y++) {
        if (val < y + std::gcd(x, y)) {
            val = y + std::gcd(x, y);
            ans = y;
        }
    }
    std::cout << ans << '\n';
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