/**
 *      author:  yuyuan567
 *      created: 2025-07-31 17:40:10
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
    int mx1 = 0, mx2 = 0;
    for (int i = 0; i < n; i++) {
        int w, h;
        cin >> w >> h;
        mx1 = max(mx1, w);
        mx2 = max(mx2, h);
    }
    cout << (mx1 + mx2) * 2 << "\n";
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