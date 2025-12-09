/**
 *      author:  yuyuan567
 *      created: 2025-08-01 16:53:32
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
    int n, q;
    cin >> n >> q;
    vector<ll> prefix_sum(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        prefix_sum[i] = prefix_sum[i - 1] + x;
    }
    auto helper = [&](ll x) -> ll {
        ll q = x / n;
        ll res = prefix_sum[n] * q;
        ll rem = x % n;
        if (rem + q <= n) {
            res += prefix_sum[rem + q] - prefix_sum[q];
        } else {
            res += prefix_sum[n] - prefix_sum[q] + prefix_sum[rem + q - n];
        }
        return res;
    };

    while (q--) {
        ll l, r;
        cin >> l >> r;
        cout << helper(r) - helper(l - 1) << "\n";
    }
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