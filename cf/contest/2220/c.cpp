#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int p, q;
    std::cin >> p >> q;
    i64 delta = i64(p + 1) * (p + 1) + 4ll * q;
    i64 sqrt = std::sqrt(delta);
    bool ok = false;
    if (sqrt * sqrt == delta) {
        ok = true;
    }
    if (!ok) {
        std::cout << -1 << '\n';
    } else {
        int n = (-p - 1 + sqrt) / 2;
        int m = p + n;
        std::cout << m << ' ' << n << '\n';
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
