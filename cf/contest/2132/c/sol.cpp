/**
 *      author:  yuyuan567
 *      created: 2025-08-22 00:25:52
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    const int MAX = 40;
    std::vector<i128> pow3(MAX);
    pow3[0] = 1;
    for (int i = 1; i < MAX; i++) {
        pow3[i] = pow3[i - 1] * 3;
    }
    while (tt--) {
        int64_t n;
        std::cin >> n;
        int64_t ans = 0;
        int idx = 0;
        while (n > 0) {
            int d = n % 3;
            if (d) {
                if (idx == 0) {
                    ans += int64_t(d) * 3LL;
                } else {
                    ans += int64_t(d) * (pow3[idx + 1] + int64_t(idx) * pow3[idx - 1]);
                }
            }
            n /= 3;
            idx++;
        }
        std::cout << ans << '\n';
    }
    return 0;
}
