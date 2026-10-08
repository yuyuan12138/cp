#include <iostream>

void solve() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cout << i << ' ';
    }
    for (int i = 1; i <= n; i++) {
        std::cout << i << ' ';
    }
    std::cout << n << ' ';
    for (int i = 1; i <= n - 1; i++) {
        std::cout << i << ' ';
    }
    for (int i = 1; i <= n; i++) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
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
