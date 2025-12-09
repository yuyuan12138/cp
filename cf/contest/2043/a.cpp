/**
 *      author:  yuyuan567
 *      created: 2025-08-02 01:53:14
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
    ll n;
    cin >> n;
    ll cnt = 1;
    while (n > 3) {
        n /= 4;
        cnt *= 2;
    }
    cout << cnt << "\n";
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
