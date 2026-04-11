/**
 *      author:  yuyuan567
 *      created: 2025-08-01 15:42:45
 */
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;

    ll sum = (k + n - 1 + k) * n / 2;
    auto get_left = [&](ll x) -> ll { return (k + k + x - 1) * x / 2; };

    ll l = 1, r = n - 1;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if ([&]() -> bool {
                ll left = get_left(mid);
                ll right = sum - left;
                return left <= right;
            }()) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    debug(n);
    debug(r);
    ll ans = min(abs(get_left(r) - sum + get_left(r)), abs(get_left(r + 1) - sum + get_left(r + 1)));
    ans = min(ans, sum);
    cout << ans << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}