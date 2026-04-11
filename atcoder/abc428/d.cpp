#include <bits/stdc++.h>

using i64 = long long;

i64 sqrt(i64 n) {
    i64 s = std::sqrt(n);
    while (s * s > n) {
        s--;
    }
    while ((s + 1) * (s + 1) <= n) {
        s++;
    }
    return s;
}


void solve() {
    i64 c, d;
    std::cin >> c >> d;
    i64 ans = 0;
    for (int bit = 1; bit <= 12; bit++) {
        i64 l = power(10ll, bit - 1) - c;
        l = std::max(l, 1ll);
        i64 r = power(10ll, bit) - 1 - c;
        r = std::min(r, d);
        ans += std::sqrt(c * power(10ll, bit) + c + r) -
               std::sqrt(c * power(10ll, bit) + c + l - 1);
        if (l > r) {
            continue;
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
