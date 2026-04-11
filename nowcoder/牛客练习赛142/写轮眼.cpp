/**
 *      author:  yuyuan567
 *      created: 2025-08-14 15:18:19
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


int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int tt = 1;
    // std::cin >> tt;
    while(tt--) {
        int n;
        std::cin >> n;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            int term = 1;
            if (x == 0) {
                ans += 8;
            }
            while (x) {
                if (x % 10 == 0) {
                    ans += term * 8;
                } 
                x /= 10;
                term *= 10;
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}