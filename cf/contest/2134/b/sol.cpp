/**
 *      author:  yuyuan567
 *      created: 2025-08-27 15:32:57
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
        int64_t k;
        std::cin >> n >> k;
        std::vector<int64_t> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            int64_t ci = a[i] % (k + 1);
            int64_t prime_a = a[i] + k * ci;
            std::cout << prime_a << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
