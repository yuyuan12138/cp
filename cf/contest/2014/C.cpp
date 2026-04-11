/**
 *      author:  yuyuan567
 *      created: 2025-07-30 23:57:29
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
#define int long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) {
        cin >> x;
    }

    auto check = [&](int mid) -> bool {
        ll mx = *max_element(all(a));
        int pos = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == mx) {
                a[i] += mid;
                pos = i;
                break;
            }
        }
        ll tot = accumulate(all(a), 0LL);

        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] * 2 * n < tot) {
                cnt++;
            }
        }
        a[pos] -= mid;
        if (cnt * 2 > n) {
            return true;
        } else {
            return false;
        }
    };
    ll l = 0, r = 1e17;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if (l != 1e17 + 1)
        cout << l << "\n";
    else
        cout << -1 << "\n";
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