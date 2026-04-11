#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int64_t init = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            init += a[i];
        } else {
            init -= a[i];
        }
    }
    int cur_odd = 0, cur_even = INT32_MAX;
    int64_t ans = init;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            ans = std::max(ans, init + cur_odd - 2 * a[i] + i);
            cur_even = std::min(2 * a[i] + i, cur_even);
            ans = std::max(ans, init + i);
        } else {
            ans = std::max(ans, init - cur_even + 2 * a[i] + i);
            cur_odd = std::max(2 * a[i] - i, cur_odd);
            ans = std::max(ans, init + i - 1);
        }
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
