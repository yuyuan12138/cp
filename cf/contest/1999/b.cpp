/**
 *      author:  yuyuan567
 *      created: 2025-08-16 01:02:58
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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int tt;
    std::cin >> tt;
    while (tt--) {
        int a1, a2, b1, b2;
        std::cin >> a1 >> a2 >> b1 >> b2;
        auto check = [](int a, int b) -> int {
            if (a > b) return 1;
            if (a == b) return 0;
            if (a < b) return -1;
        };
        int ans = 0;
        if (check(a1, b1) + check(a2, b2) > 0) {
            ans++;
        }
        if (check(a1, b2) + check(a2, b1) > 0) {
            ans++;
        }
        if (check(a2, b1) + check(a1, b2) > 0) {
            ans++;
        }

        if (check(a2, b2) + check(a1, b1) > 0) {
            ans++;
        }
        std::cout << ans << '\n';


    }
    return 0;
}
