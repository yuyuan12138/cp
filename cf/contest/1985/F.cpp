/**
 *      author:  yuyuan567
 *      created: 2025-08-02 15:47:59
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
    ll n, h;
    cin >> h >> n;
    vector<ll> a(n);
    vector<ll> c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    ll l = 0, r = 1e17;

    auto check = [&](ll x) -> bool {
        unsigned long long tot = 0;
        for (int i = 0; i < n; i++) {
            if (tot >= h) {
                return true;
            }
            tot += a[i] * (x / c[i] + 1);
        }
        if (tot >= h) {
            return true;
        } else {
            return false;
        }
    };
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << l + 1 << "\n";

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