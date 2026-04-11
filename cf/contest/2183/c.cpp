#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    auto check = [&](int x) -> bool {
        int half = (x - 1) / 2;
        int min = std::min({half, k - 1, n - k});
        int last = x - 1 - min;

    };
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