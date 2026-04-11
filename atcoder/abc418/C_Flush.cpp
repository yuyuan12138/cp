/**
 *      author:  yuyuan567
 *      created: 2025-08-10 14:35:18
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

void solve(){
    ll n, q;
    std::cin >> n >> q;
    std::vector<ll> a(n);
    ll mx = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        mx = std::max(mx, a[i]);
    }
    std::sort(all(a));
    std::vector<ll> pre_sum(n);
    pre_sum[0] = a[0];
    for (int i = 1; i < n; i++) {
        pre_sum[i] = pre_sum[i - 1] + a[i];
    }
    while (q--) {
        ll x;
        std::cin >> x;
        if (x > mx) {
            std::cout << "-1\n";
        } else {
            auto it = std::lower_bound(all(a), x);
            if (it == a.begin()) {
                std::cout << n * (x - 1) + 1 << "\n";
                continue;
            }
            ll idx = std::distance(a.begin(), it) - 1;
            ll ans = 0;
            ans += pre_sum[idx];
            ans += (n - idx - 1) * (x - 1);
            std::cout << ans + 1 << "\n";
        }
    }
    return ;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    solve();
    return 0;
}