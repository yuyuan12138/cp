#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = n; i >= 1; i--) {
        std::cout << i << " ";
    }
    std::cout << n << " ";
    for (int i = 1; i <= n - 1; i++) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
