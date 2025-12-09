/**
 *      author:  yuyuan567
 *      created: 2025-08-30 12:12:41
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
        int a, b, c;
        std::cin >> a >> b >> c;
        if (a == b) {
            std::cout << c << '\n';
        } else if (a == c) {
            std::cout << b << '\n';
        } else {
            std::cout << a << '\n';
        }
    }
    return 0;
}
