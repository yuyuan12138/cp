#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    int y, r;
    std::cin >> y >> r;
    std::cout << std::min(n, y / 2 + r) << '\n';
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