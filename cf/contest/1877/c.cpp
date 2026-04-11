#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    i64 ans = 0;
    if (k == 1) {
        ans++;
    }
    if (k == 2) {
        if (m <= n) {
            ans += m;
        } else {
            ans += n + (m - n) / n;
        }
    }
    if (k == 3) {
        if (m > n) {
            ans += m - n - (m - n) / n;
        }
    }
    std::cout << ans << '\n';
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