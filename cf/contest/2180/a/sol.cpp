#include <bits/stdc++.h>

void solve() {
    int l, a, b;
    std::cin >> l >> a >> b;
    int g = std::gcd(l, b);
    std::cout << (l - a - 1) / g * g + a << '\n';
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

