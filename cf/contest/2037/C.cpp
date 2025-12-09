/**
 *      author:  yuyuan567
 *      created: 2025-07-30 22:15:21
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
    if (n <= 4) {
        cout << "-1\n";
    } else {
        for (int i = 1; i <= n; i += 2) {
            if (i != 5)
                cout << i << " ";
        }
        cout << "5 4 ";

        for (int i = 2; i <= n; i += 2) {
            if (i != 4) {
                cout << i << " ";
            }
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