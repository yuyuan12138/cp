#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

constexpr int inf = 1e9 + 1;

void solve() {
    i64 n;
    std::cin >> n;
    std::cout << std::max(1LL, n * (n - 1)) << '\n';
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