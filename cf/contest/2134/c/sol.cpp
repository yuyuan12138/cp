/**
 *      author:  yuyuan567
 *      created: 2025-08-27 15:41:03
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
        std::vector<int64_t> a(n + 1);
        int64_t tot = 0;
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
            tot += a[i];
        }
        int n0 = n;
        if (n % 2 == 0) {
            a.push_back(0);
            ++n;
        } else {
            a.push_back(0);
        }
        std::vector<int64_t> b(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                b[i] = a[i];
            }
        }
        for (int i = 1; i <= n; i += 2) {
            int64_t mx = a[i];
            if (i + 1 <= n) {
                mx = std::min(mx, a[i + 1]);
            }
            if (i - 1 >= 1) {
                if (i - 2 >= 1) {
                    mx = std::min(mx, a[i - 1] - b[i - 2]);
                }
            }
            b[i] = std::max(mx, 0LL);
        }
        for (int i = 1; i <= n0; i++) {
            tot -= b[i];
        }
        std::cout << tot << '\n';
    }
    return 0;
}
