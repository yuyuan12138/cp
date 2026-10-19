#include <bits/stdc++.h>

using i64 = long long;
using i128 = __int128;


void solve() {
    int n;
    i64 x;
    std::cin >> n >> x;
    std::vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i] >> c[i];
    }
    i64 tot = 0;
    for (int i = 0; i < n; i++) {
        tot += i64(a[i]) * (b[i] - 1);
    }
    if (tot >= x) {
        std::cout << 0 << '\n';
    } else {
        i64 max = -1e9;
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (max <= std::max(i64(a[i]) * b[i] - c[i], max)) {
                max = std::max(i64(a[i]) * b[i] - c[i], max);
                idx = i;
            }
        }
        if (max <= 0) {
            std::cout << -1 << '\n';
            return ;
        }
        x -= tot;
        auto check = [&](i64 x_) -> bool {
            i128 f = a[idx] + i128(x_ - 1) * a[idx] * b[idx] - i128(c[idx]) * x_ + i128(a[idx]) * (b[idx] - 1);
            return f >= x;
        };
        i64 l = 0, r = 1e18;
        while (l <= r) {
            i64 mid = l + (r - l) / 2;
            if (check(mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        std::cout << l << '\n';
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