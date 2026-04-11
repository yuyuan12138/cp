#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int64_t tot = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        tot += a[i];
    }
    tot /= n;
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        ans += std::max(int64_t(a[i]) - tot, int64_t(0));
    }
    std::cout << ans << '\n';
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
