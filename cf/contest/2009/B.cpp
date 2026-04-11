/**
 *      author:  yuyuan567
 *      created: 2025-08-01 15:14:00
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
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] == '#') {
                flag = j;
            }
        }
        ans.push_back(flag + 1);
    }

    for (int i = n - 1; i >= 0; i--) {
        cout << ans[i] << ' ';
    }
    cout << "\n";

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