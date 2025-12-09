/**
 *      author:  yuyuan567
 *      created: 2025-08-27 16:26:48
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

        std::vector<int> d(n + 3);
        std::vector<int> a(n + 1);
        for (int i = n; i >= 1; i--) {
            if (d[i + 1] == d[i + 2]) {
                d[i] = d[i + 1] + 1;
            } else {
                std::cout << "throw " << i << std::endl;
                std::cin >> d[i];
                if (d[i] == d[i + 1] + 1) {
                    a[i] = 1;
                } else {
                    a[i] = 2;
                }
            }
        }
        for (int i = 1; i <= n - 1; i++) {
            if (a[i] == 0) {
                std::cout << "swap " << i << std::endl;
                std::cout << "throw " << i + 1 << std::endl;
                int x;
                std::cin >> x;
                if (x == d[i + 2] + 1) {
                    a[i] = 1;
                } else {
                    a[i] = 2;
                }
            }
        }
        std::cout << "swap " << n - 1 << std::endl;
        std::cout << "throw " << n - 1 << std::endl;
        int x;
        std::cin >> x;
        if (x == 2) {
            a[n] = 1;
        } else {
            a[n] = 2;
        }
        std::cout << "! "; 
        for (int i = 1; i <= n; i++) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
