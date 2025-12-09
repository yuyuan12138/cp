/**
 *      author:  yuyuan567
 *      created: 2025-08-27 19:43:10
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
        if (n % 2) {
            std::cout << "Kosuke\n";
        } else {
            std::cout << "Sakurako\n";
        }
    }
    return 0;
}
