/**
 *      author:  yuyuan567
 *      created: 2025-08-01 15:27:13
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

struct Point {
    int x, y;
};

void solve() {
    int n;
    cin >> n;
    vector<vector<ll>> grids(2, vector<ll>(n + 1));
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        grids[y][x] = 1;
    }
    vector<vector<ll>> prefix_sum(2, vector<ll>(n + 1));
    prefix_sum[0][0] = grids[0][0];
    prefix_sum[1][0] = grids[1][0];
    for (int i = 1; i <= n; i++) {
        prefix_sum[0][i] = prefix_sum[0][i - 1] + grids[0][i];
        prefix_sum[1][i] = prefix_sum[1][i - 1] + grids[1][i];
    }

    ll cnt = 0;
    for (int i = 0; i <= n; i++) {
        if (grids[0][i] == 1 && grids[1][i] == 1) {
            if (i > 0) {
                cnt += prefix_sum[0][i - 1];
                cnt += prefix_sum[1][i - 1];
            }
            if (i <= n) {
                cnt += prefix_sum[0][n] - prefix_sum[0][i];
                cnt += prefix_sum[1][n] - prefix_sum[1][i];
            }
        }
        if (grids[0][i] == 1 && (i > 0 && i < n) && (grids[1][i - 1] == 1 && grids[1][i + 1] == 1)) {
            cnt++;
        }
        if (grids[1][i] == 1 && (i > 0 && i < n) && (grids[0][i - 1] == 1 && grids[0][i + 1] == 1)) {
            cnt++;
        }
    }
    cout << cnt << "\n";

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