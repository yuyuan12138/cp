/**
 *      author:  yuyuan567
 *      created: 2025-08-29 23:49:42
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
        int64_t mn1 = INT64_MAX, mn2 = INT64_MAX;
        for (int i = 0; i < n; i++) {
            int64_t x, y;
            std::cin >> x >> y;
            mn1 = std::min(y - x, mn1);
            mn2 = std::min(x + y, mn2);
        }
        const int64_t move = 400000000LL;
        const int64_t step = 100000000LL;
        int64_t res1, res2;
        std::cout << "? L " << step << std::endl;
        std::cin >> res1;
        std::cout << "? L " << step << std::endl;
        std::cin >> res1;
        std::cout << "? U " << step << std::endl;
        std::cin >> res1;
        std::cout << "? U " << step << std::endl;
        std::cin >> res1;
        int64_t sum1 = res1 - move - mn1;
        std::cout << "? D " << step << std::endl;
        std::cin >> res2;
        std::cout << "? D " << step << std::endl;
        std::cin >> res2;
        std::cout << "? D " << step << std::endl;
        std::cin >> res2;
        std::cout << "? D " << step << std::endl;
        std::cin >> res2;
        int64_t sum2 = res2 - move - mn2;
        std::cout << "! " << (0LL - sum1 - sum2) / 2 << " " << (sum1 - sum2) / 2 << std::endl;
    }
    return 0;
}
