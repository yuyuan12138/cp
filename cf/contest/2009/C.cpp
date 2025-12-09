/**
 *      author:  yuyuan567
 *      created: 2025-08-01 15:17:25
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
    int x, y, k;
    cin >> x >> y >> k;

    int ans1 = (x + k - 1) / k;
    int ans2 = (y + k - 1) / k;

    if (ans1 == ans2) {
        cout << ans1 + ans2 << "\n";
    } else if (ans1 > ans2) {
        cout << ans1 * 2 - 1 << "\n";
    } else {
        cout << ans2 * 2 << "\n";
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