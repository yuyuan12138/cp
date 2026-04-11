/**
 *      author:  yuyuan567
 *      created: 2025-08-02 15:04:32
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
    int n;
    cin >> n;
    int ans = 0;
    ll mx = 0LL;
    ll pre_sum = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        mx = max(mx, x);
        pre_sum += x;
        if (pre_sum - mx == mx) {
            ans++;
        }
    }
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