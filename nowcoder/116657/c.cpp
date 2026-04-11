#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    // 2 2 -> 2, 1 2 -> 1, 1 1 -> 1
    if (n == 2) {
        std::cout << "-1\n";
        return ;
    }
    if (n % 2 == 1) {
        for (int i = 1; i <= n; i++) {
            std::cout << i << " \n"[i == n];
        }
    } else {
        for (int i = 1; i <= n - 2; i++) {
            std::cout << i << " ";
        }
        std::cout << n << " " << n - 1 << '\n';
    }
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
