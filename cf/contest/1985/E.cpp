/**
 *      author:  yuyuan567
 *      created: 2025-08-02 15:27:21
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
    ll x, y, z, k;
    cin >> x >> y >> z >> k;

    ll tot = 0;

    for (ll i = 1; i <= x; i++) {
        for (ll j = 1; j <= y; j++) {
            if (k % (i * j) != 0 || (i * j > k)) {
                continue;
            }
            if (k / (i * j) > z) {
                continue;
            }
            ll h = k / (i * j);
            tot = max(tot, (x - i + 1) * (y - j + 1) * (z - h + 1));
        }
    }
    cout << tot << "\n";
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