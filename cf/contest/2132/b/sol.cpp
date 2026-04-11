/**
 *      author:  yuyuan567
 *      created: 2025-08-22 00:38:29
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
        int64_t n; std::cin >> n;
        std::vector<int64_t> res;
        int64_t p = 10;
        while (p < n) {
            int64_t d = p + 1;
            if (d > n) break;
            if (n % d == 0) {
                res.push_back(n / d);
            }
            p *= 10;
        }
        if (res.empty()) {
            std::cout << "0\n";
        } else {
            std::sort(res.begin(), res.end());
            std::cout << res.size() << '\n';
            for (auto x: res) {
                std::cout << x << ' ';
            }
            std::cout << '\n';
        }
    }
    return 0;
}
