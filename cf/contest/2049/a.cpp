/**
 *      author:  yuyuan567
 *      created: 2025-07-28 14:53:24
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
    vector<int> a(n + 1);
    bool has_zero = false;
    bool all_zero = true;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 0)
            has_zero = true;
        else
            all_zero = false;
    }

    if (all_zero) {
        cout << "0\n";
    } else if (!has_zero) {
        cout << "1\n";
    } else {
        int l = 0, r = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] != 0) {
                l = i;
                break;
            }
        }
        for (int i = n; i >= 1; i--) {
            if (a[i] != 0) {
                r = i;
                break;
            }
        }

        for (int i = l; i <= r; i++) {
            if (a[i] == 0) {
                cout << "2\n";
                return;
            }
        }
        cout << "1\n";
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