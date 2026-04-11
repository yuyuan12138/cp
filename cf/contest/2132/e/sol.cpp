/**
 *      author:  yuyuan567
 *      created: 2025-08-22 00:09:36
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
        int n, m, q;
        std::cin >> n >> m >> q;
        std::vector<int64_t> a(n), b(m);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            std::cin >> b[i];
        }
        std::sort(a.begin(), a.end(), std::greater<int64_t>());
        std::sort(b.begin(), b.end(), std::greater<int64_t>());
        std::vector<int64_t> pa(n + 1), pb(m + 1);
        for (int i = 1; i <= n; i++) {
            pa[i] = pa[i - 1] + a[i - 1];
        }
        for (int i = 1; i <= m; i++) {
            pb[i] = pb[i - 1] + b[i - 1];
        }
        while (q--) {
            int x, y, z;
            std::cin >> x >> y >> z;
            int L = std::max(0, z - y);
            int R = std::min(z, x);
            int l = L, r = R;
            auto check = [&](int x) -> int64_t {
                int t = z - x;
                return pa[x] + pb[t];
            };
            while (r - l > 3) {
                if (check(l + (r - l) / 3) < check(r - (r - l) / 3)) {
                    l = l + (r - l) / 3;
                } else {
                    r = r - (r - l) / 3;
                }
            }
            int64_t ans = LLONG_MIN;
            for (int i = l; i <= r; i++) {
                ans = std::max(ans, check(i));
            }
            std::cout << ans << '\n';
        }
    }
    return 0;
}
