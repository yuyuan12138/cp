/**
 *      author:  yuyuan567
 *      created: 2025-07-30 18:03:24
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
    vector<ll> a(n);
    ll tot_cars = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tot_cars += a[i];
    }
    // sort(all(a));
    ll l = 0, r = 1e9;
    auto check = [&](int mid) {
        ll c1 = 0, c2 = 0;
        ll t1 = 0, t2 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < mid) {
                c1 += mid - a[i];
                t1++;
            } else if (a[i] >= mid + k) {
                c2 += a[i] - (mid + k);
                t2++;
            }
        }
        if (c1 < c2) {
            return -1;
        }
        if (c2 + t2 <= c1 - t1)
            return 1;
        return 0;
    };
    ll res = 0;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        ll c_r = check(mid);
        if (c_r == -1) {
            l = mid + 1;
        } else if (c_r == 1) {
            r = mid - 1;
        } else {
            ll z = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] < mid) {
                    z += mid - a[i];
                    res += (mid - a[i]) * k;
                    a[i] = mid;
                } else if (a[i] > mid + k) {
                    z -= a[i] - mid - k;
                    a[i] = mid + k;
                }
            }
            z = abs(z);
            for (int i = 0; i < n; i++) {
                if (a[i] == mid && z > 0) {
                    z--;
                    a[i]--;
                    res -= k;
                } else if (a[i] == mid + k && z > 0) {
                    z--;
                    a[i]--;
                }
            }
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        res += a[i] * (a[i] + 1) / 2;
    }
    cout << res << "\n";
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