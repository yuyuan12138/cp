/**
 *      author:  yuyuan567
 *      created: 2025-08-03 00:21:15
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
    }

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if ((r - l + 1) % 2) {
            cout << "NO\n";
        } else {
            if (rq.query(l, r) == 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
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