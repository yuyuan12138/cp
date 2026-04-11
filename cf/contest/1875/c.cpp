#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    n %= m;
    int a = n / std::gcd(n, m);
    int b = m / std::gcd(n, m);
    if (__builtin_popcount(b) > 1) {
        std::cout << -1 << '\n';
    } else {
        std::cout << __builtin_popcount(a) * m - n << '\n';
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