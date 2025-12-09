/**
 *      author:  yuyuan567
 *      created: 2025-08-30 20:04:18
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
    std::string x, y;
    std::cin >> x >> y;
    std::vector<std::string> f(10);
    f[0] = x, f[1] = y;
    for (int i = 2; i < 10; i++) {
        int64_t t = std::stoll(f[i - 2]) + std::stoll(f[i - 1]);
        f[i] = std::to_string(t);
        std::reverse(f[i].begin(), f[i].end());
        t = std::stoll(f[i]);
        f[i] = std::to_string(t);
    }
    std::cout << f[9];
    return 0;
}
