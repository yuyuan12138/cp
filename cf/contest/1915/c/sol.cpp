/**
 *      author:  yuyuan567
 *      created: 2025-08-30 12:21:28
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
        int64_t tot = 0;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            tot += x;
        }
        bool ok = false;
        for (int64_t i = 1; i * i <= tot; i++) {
            if (i * i == tot) {
                ok = true;
            }
        }
        std::cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
