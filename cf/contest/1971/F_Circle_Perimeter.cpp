/**
 *      author:  yuyuan567
 *      created: 2025-08-03 17:07:07
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
using ull = unsigned long long;

void solve() {
    ll r;
    cin >> r;
    ll height = r;
    ll ans = 0;
    for (ll i = 0; i <= r; i++) {
        while (i * i + height * height >= (r + 1) * (r + 1)) {
            height--;
        }
        ll cnt = height;
        while (i * i + cnt * cnt >= r * r && cnt > 0) {
            cnt--;
            ans++;
        }
    }
    cout << ans * 4 << "\n";
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