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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        
        std::vector<int64_t> f(n + 1);

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                f[i] = a[i];
            } else if (i == 1) {
                f[i] = f[i - 1] + a[i] - 1;
            } else {
                f[i] = f[i - 1] + a[i] - 1;
                f[i] = std::min(f[i], f[i - 2] + a[i - 1] + std::max(a[i] - i, 0));
            }
        }
        std::cout << f[n - 1] << '\n';
    }
    return 0;
}
