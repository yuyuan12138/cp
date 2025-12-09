/**
 *      author:  yuyuan567
 *      created: 2025-08-30 16:24:55
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
    int x, y;
    std::cin >> x >> y;
    std::cout << (x + y - 1) % 12 + 1;
    return 0;
}
