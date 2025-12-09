#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::cout << (n / 2) - (n % 2 == 0) << '\n';
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