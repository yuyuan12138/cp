/**
 *      author:  yuyuan567
 *      created: 2025-08-20 17:39:53
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using ll = unsigned long long;
using ull = unsigned long long;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        ll l, r;
        ll i, k;
        std::cin >> l >> r >> i >> k;
        auto get_range = [](ll x, ll y) -> ll {
            ll l = x - 1;
            if (l % 4 == 0) {
                l = l;
            } else if (l % 4 == 1) {
                l = 1;
            } else if(l % 4 == 2) {
                l = l + 1;
            } else if (l % 4 == 3) {
                l = 0;
            }
            ll r = y;
            if (r % 4 == 0) {
                r = r;
            } else if (r % 4 == 1) {
                r = 1;
            } else if (r % 4 == 2) {
                r = r + 1;
            } else if (r % 4 == 3) {
                r = 0;
            }
            return (l ^ r);
        };
        ll hi = get_range((l - k + (1 << i) - 1) >> i, (r - k) >> i) << i;
        ll lo = k * (((r - k) / (1 << i) - (l - k - 1) / (1 << i)) & 1);
        std::cout << (get_range(l, r) ^ hi ^ lo) << '\n';
    }
    return 0;
}
