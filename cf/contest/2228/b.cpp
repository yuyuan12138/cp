#include <bits/stdc++.h>

void solve() {
    int n, x1, x2, k;
    std::cin >> n >> x1 >> x2 >> k;
    if (n <= 3) {
        std::cout << 1 << '\n';
    } else {
        std::cout << std::min(std::abs(x1 - x2), n - std::abs(x1 - x2)) + k
                  << '\n';
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
