/**
 *      author:  yuyuan567
 *      created: 2025-07-30 23:52:23
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
    int n, k;
    cin >> n >> k;
    cout << (((n + 1) * n / 2 - (n - k) * (n - k + 1) / 2) % 2 ? "NO" : "YES") << '\n';
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