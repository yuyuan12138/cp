/**
 *      author:  yuyuan567
 *      created: 2025-08-02 15:19:46
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
    int n, m;
    cin >> n >> m;
    vector<string> grids(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> grids[i];
        for (int j = 0; j < m; j++) {
            if (grids[i][j] == '#') {
                cnt++;
}
        }
    }
    if (cnt == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grids[i][j] == '#') {
                    cout << i + 1 << " " << j + 1 << "\n";
                    return;
                }
            }
        }
    } else {
        int h = 0;
        for (int i = 1; i <= max(n, m); i++) {
            if (2 * i * i + 2 * i + 1 - cnt == 0) {
                h = i;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grids[i][j] == '#') {
                    cout << i + h + 1 << " " << j + 1 << "\n";
                    return;
                }
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