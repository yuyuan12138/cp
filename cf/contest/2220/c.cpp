#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int p, q;
    std::cin >> p >> q;
    int sum = p + 2 * q;
    for (int n = 1; n * n <= sum; n++) {
        if ((sum - n) % (2 * n + 1) == 0) {
            int m = (sum - n) / (2 * n + 1);
            if (std::abs(m - n) <= p) {
                std::cout << m << ' ' << n << '\n';
                return;
            }
        }
    }
    std::cout << -1 << '\n';
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
