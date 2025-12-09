#include <bits/stdc++.h>

void solve() {
    int x;
    std::cin >> x;
    auto is_prime = [](int x) -> bool {
        if (x == 1) {
            return true;
        }
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    };
    for (int i = 1; i < x; i++) {
        if (!is_prime(i ^ x) && (i ^ x) >= 2) {
            std::cout << i << '\n';
            return ;
        }
    }
    std::cout << "-1\n";
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

