/**
 *      author:  yuyuan567
 *      created: 2025-08-27 20:01:32
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
        }
        int ans = 0;
        for (int i = n / 2 - 1; i >= 1; i--) {
            if (a[i] == a[i + 1] || a[n - i] == a[n - i + 1]) {
                std::swap(a[i], a[n - i + 1]);       
            }
        }
        for (int i = 1; i <= n - 1; i++) {
            ans += (a[i] == a[i + 1]);
        }

        std::cout << ans << '\n';
    }
    return 0;
}
