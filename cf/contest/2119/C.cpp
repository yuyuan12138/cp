/**
 *      author:  yuyuan567
 *      created: 2025-07-28 13:22:55
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

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    ll n, l, r, k;
    cin >> n >> l >> r >> k;
    if (n & 1) {
        cout << l << "\n";
    } else {
        if (n == 2) {
            cout << "-1\n";
        } else {
            ll res = 1LL;
            while (res <= r) {
                if (res > l) {
                    if (k <= n - 2) {
                        cout << l << "\n";
                    } else {
                        cout << res << "\n";
                    }

                    return;
                }
                res <<= 1;
            }
            cout << "-1\n";
        }
    }

    return;
}

int main() {
    speedup();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}