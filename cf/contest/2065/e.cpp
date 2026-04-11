/**
 *      author:  yuyuan567
 *      created: 2025-08-15 15:02:28
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

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt;
    std::cin >> tt;
    while (tt--) {
        int n, m, k;
        std::cin >> m >> n >> k;
        if (std::abs(n - m) > k || (n < k && m < k)) {
            std::cout << "-1\n";
        } else {
            std::string res = "";
            if (n >= m) {
                for (int i = 0; i < k; i++) {
                    res += "1";
                }
                if (n - k > m) {
                    res = "-1";
                } else {
                    for (int i = 0; i < n - k; i++) {
                        res += "01";
                    }
                    for (int i = 0; i < m - n + k; i++) {
                        res += "0";
                    }
                }
            } else {
                for (int i = 0; i < k; i++) {
                    res += "0";
                }
                if (m - k > n) {
                    res = "-1";
                } else {
                    for (int i = 0; i < m - k; i++) {
                        res += "10";
                    }
                    for (int i = 0; i < n - m + k; i++) {
                        res += "1";
                    }
                }
            }
            std::cout << res << "\n";
        }
    }

    return 0;
}