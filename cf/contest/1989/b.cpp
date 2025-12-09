#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    std::string a, b;
    std::cin >> a >> b;
    const int n = a.size();
    const int m = b.size();
    int ans = INT32_MAX;
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (int k = i, j = 0; k < m; k++) {
            while (j < n && a[j] != b[k]) {
                j++;
            }
            if (j < n) {
                cnt++;
                j++;
            }
        }
        ans = std::min(ans, n + m - cnt);
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