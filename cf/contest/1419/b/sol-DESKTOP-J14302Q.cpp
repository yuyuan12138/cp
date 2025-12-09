/**
 *      author:  yuyuan567
 *      created: 2025-08-31 09:11:46
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
        int64_t x;
        std::cin >> x;
        int ans = 0;
        int64_t cur = 1;
        int64_t tot = 0;
        auto cal = [](int64_t x) -> int64_t { return 1LL * (x + 1) * x / 2; };
        while (cal(cur) + tot <= x) {
            ans++;
            tot += cal(cur);
            cur = 2LL * cur + 1LL;
        }
        std::cout << ans << '\n';
    }
    return 0;
}
