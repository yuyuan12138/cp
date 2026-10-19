/**
 *      author:  yuyuan567
 *      created: 2025-08-24 23:47:03
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<int64_t> dp(n);
    dp[0] = a[0];
    for (int i = 0; i < n - 1; i++) {
        dp[i + 1] = dp[i] + a[i + 1] - 1;
        if (i > 0) 
            dp[i + 1] = std::min(dp[i + 1], dp[i - 1] + a[i] + std::max(0, a[i + 1] - i - 1));
    }
    std::cout << dp[n - 1] << '\n';
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
