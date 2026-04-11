/**
 *      author:  yuyuan567
 *      created: 2025-08-24 22:41:33
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
        std::vector<int> g(n);
        for (int i = 0; i < n; i++) {
            std::cin >> g[i];
        }
        std::sort(g.begin(), g.end());
        int64_t tot = 0;
        for (int i = n - 1; i >= 0; i -= 2) {
            if (i - 1 < 0) {
                break;
            }
            tot += g[i];
        }
        if (n % 2 == 1) {
            tot += g[0];
        }
        std::cout << tot << '\n';
    }
    return 0;
}
