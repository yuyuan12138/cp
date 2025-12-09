/**
 *      author:  yuyuan567
 *      created: 2025-08-27 15:22:29
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
        int n, a, b;
        std::cin >> n >> a >> b;
        if (n % 2 == 0) {
            if (a < b) {
                if (b % 2 == 0) {
                    std::cout << "YES\n";
                } else {
                    std::cout << "NO\n";
                }
            } else {
                if (b % 2 == 1 || a % 2 == 1) {
                    std::cout << "NO\n";
                } else {
                    std::cout << "YES\n";
                }
            }
        } else {
            if (a < b) {
                if (b % 2 == 1) {
                    std::cout << "YES\n";
                } else {
                    std::cout << "NO\n";
                }
            } else {
                if (b % 2 == 0 || a % 2 == 0) {
                    std::cout << "NO\n";
                } else {
                    std::cout << "YES\n";
                }
            }
        }
    }
    return 0;
}
