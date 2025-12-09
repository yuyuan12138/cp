/**
 *      author:  yuyuan567
 *      created: 2025-08-17 16:10:55
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    int R_min = 1e9 + 7, C_min = 1e9 + 7, R_max = 0, C_max = 0;
    for (int i = 0; i < n; i++) {
        int r, c;
        std::cin >> r >> c;
        R_min = std::min(R_min, r);
        C_min = std::min(C_min, c);
        R_max = std::max(R_max, r);
        C_max = std::max(C_max, c);
    }
    std::cout << (std::max(R_max - R_min, C_max - C_min) + 1) / 2;
    return 0;
}
