/**
 *      author:  yuyuan567
 *      created: 2025-08-10 21:21:17
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
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<std::pair<int, int>> v;
    ll ans = 0;
    for (int i = 0, b; i < n; i++) {
        std::cin >> b;
        if (b < a[i]) {
            std::swap(a[i], b);
        }
        ans += b - a[i];
        v.push_back({a[i], b});
    }
    std::sort(all(v));
    for (int i = 1; i < n; i++)
        if (v[i].first <= v[i - 1].second) {
            std::cout << ans << '\n';
            return;
        }
    int mn = __INT32_MAX__;
    for (int i = 1; i < n; i++)
        mn = std::min(mn, v[i].first - v[i - 1].second);
    std::cout << ans + 2 * mn << "\n";
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}