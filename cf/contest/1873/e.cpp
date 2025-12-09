#include <bits/stdc++.h>

void solve() {
    int64_t n, x;
    std::cin >> n >> x;
    std::vector<int64_t> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    auto check = [&](const int64_t h) -> bool {
        int64_t sum = 0;
        for (int i = 0; i < n; i++) {
            sum += std::max(h - a[i], 0LL);
        }
        if (sum > x) {
            return true;
        } else {
            return false;
        }
    };
    int64_t lo = 1, hi = 2E12;
    while (lo <= hi) {
        int64_t mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    std::cout << hi << '\n';
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
