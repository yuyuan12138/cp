#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;
    while (n > 1 && k > 0) {
        n = (n + 1) / 2;
        k--;
    }
    std::cout << n << '\n';
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
