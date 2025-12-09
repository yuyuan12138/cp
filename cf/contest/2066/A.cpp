/**
 *      author:  yuyuan567
 *      created: 2025-07-28 14:03:47
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
    int n;
    cin >> n;
    vector<int> x(n + 1), isx(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        isx[x[i]] = 1;
    }
    if (accumulate(isx.begin(), isx.end(), 0) == n) {
        int i1 = 0, in = 0;
        for (int i = 1; i <= n; i++) {
            if (x[i] == 1) {
                i1 = i;
            }
            if (x[i] == n) {
                in = i;
            }
        }
        cout << "? " << i1 << ' ' << in << endl;
        int ans;
        cin >> ans;
        if (ans < n - 1) {
            cout << "! A" << endl;
        } else if (ans > n - 1) {
            cout << "! B" << endl;
        } else {
            cout << "? " << in << ' ' << i1 << endl;
            cin >> ans;
            if (ans == n - 1) {
                cout << "! B" << endl;
            } else {
                cout << "! A" << endl;
            }
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (!isx[i]) {
                cout << "? " << i << ' ' << 1 + (i == 1) << endl;
                int ans;
                cin >> ans;
                if (ans == 0) {
                    cout << "! A" << endl;
                } else {
                    cout << "! B" << endl;
                }
                return;
            }
        }
    }
}

int main() {
    speedup();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}