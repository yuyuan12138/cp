/**
 *      author:  yuyuan567
 *      created: 2025-07-31 22:49:03
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
    int n, s;
    cin >> n >> s;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            cnt0++;
        }
        if (x == 1) {
            cnt1++;
        }
        if (x == 2) {
            cnt2++;
        }
    }
    if (s - cnt1 - cnt2 * 2 == 0 || s - cnt1 - cnt2 * 2 >= 2) {
        cout << "-1\n";
    } else {
        while (cnt0--) {
            cout << "0 ";
        }
        while (cnt2--) {
            cout << "2 ";
        }
        while (cnt1--) {
            cout << "1 ";
        }
        cout << "\n";
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