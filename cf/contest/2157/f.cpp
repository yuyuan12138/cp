#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

constexpr int N = 250000;

void solve() {
    i64 ans = 1e18;
    int idx = 0;
    for (int k = 2; k <= N; k++) {
        if (ans > i64(N / k) * 1000 + i64(k) * N) {
            ans = i64(k) * 1000 + i64(k) * N;
            idx = k;
        }
    }
    std::cout << idx << '\n';
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}