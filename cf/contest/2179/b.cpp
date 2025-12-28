#include <bits/stdc++.h>

constexpr int inf = 1e9;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int sum = 0;
    for (int i = 1; i < n; i++) {
        sum += std::abs(a[i] - a[i - 1]);
    }
    int ans = inf;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            sum -= std::abs(a[i] - a[i - 1]);
        }
        if (i < n - 1) {
            sum -= std::abs(a[i + 1] - a[i]);
        }
        if (i > 0 && i < n - 1) {
            sum += std::abs(a[i + 1] - a[i - 1]);
        }
        ans = std::min(ans, sum);
        if (i > 0) {
            sum += std::abs(a[i] - a[i - 1]);
        }
        if (i < n - 1) {
            sum += std::abs(a[i + 1] - a[i]);
        }
        if (i > 0 && i < n - 1) {
            sum -= std::abs(a[i + 1] - a[i - 1]);
        }
    }

    std::cout << ans << '\n';

    return ;
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