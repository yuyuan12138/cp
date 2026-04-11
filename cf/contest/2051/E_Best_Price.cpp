/**
 *      author:  yuyuan567
 *      created: 2025-08-03 22:14:36
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "../../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), b(n), candidates;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        candidates.push_back(a[i]);
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        candidates.push_back(b[i]);
    }

    std::sort(all(a));
    std::sort(all(b));
    std::sort(all(candidates));
    ll ans = 0LL;
    for (int i = 0; i < 2 * n; i++) {
        int cost = candidates[i];
        auto it_a = std::lower_bound(all(a), cost);
        int dis_a = std::distance(it_a, a.end());
        auto it_b = std::lower_bound(all(b), cost);
        int dis_b = std::distance(b.begin(), it_b);
        int negative = n - dis_b - dis_a;
        if (n - dis_b - dis_a > k) {
            continue;
        }
        if (ans < 1LL * cost * dis_a + 1LL * negative * cost) {
            ans = 1LL * cost * dis_a + 1LL * negative * cost;
            debug(cost);
            debug(dis_a);
            debug(dis_b);
        }
    }
    debug("NONE");
    std::cout << ans << "\n";
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}