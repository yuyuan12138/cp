/**
 *      author:  yuyuan567
 *      created: 2025-08-29 13:51:33
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
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        if (a > c || b > d || a > b * 2 + 2 || b > a * 2 + 2 || (c - a) > (d - b) * 2 + 2 ||
            (d - b) > (c - a) * 2 + 2) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
    }
    return 0;
}
