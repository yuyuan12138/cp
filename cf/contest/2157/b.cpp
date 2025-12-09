#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, x, y;
    std::cin >> n >> x >> y;
    std::string s;
    std::cin >> s;
    int cnt = std::count(s.begin(), s.end(), '4');
    if (std::abs(x) > n || std::abs(y) > n) {
        std::cout << "NO\n";
    } else {
        if (std::abs(x) + std::abs(y) > 2 * n - cnt) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
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
    return 0;
}