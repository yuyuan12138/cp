/**
 *      author:  yuyuan567
 *      created: 2025-08-21 13:12:33
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
        int x, y, k;
        std::cin >> x >> y >> k;
        int mn = std::min(x, y);
        std::cout << "0 0 " << mn << " " << mn << '\n';
        std::cout << mn << " " << 0 << " 0 " << mn << '\n';

    }
    return 0;
}
