#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = n - 2; i >= 0; i--) {
        a[i] = std::max(a[i], a[i + 1] + a[i]);
        ans += (a[i] > 0);
    }
    std::cout << ans + (a.back() > 0) << '\n';
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
