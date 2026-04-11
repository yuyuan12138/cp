/**
 *      author:  yuyuan567
 *      created: 2025-07-28 14:06:35
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
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<vector<ll>> grids(n + 1, vector<ll>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grids[i][j];
        }
    }
    // debug(n + 1);
    int cur_x = 1, cur_y = 1;
    for (char c : s) {
        if (c == 'D') {
            ll tot = 0;
            for (int i = 1; i <= m; i++) {
                tot += grids[cur_x][i];
            }
            grids[cur_x][cur_y] = -tot;
            cur_x++;
        } else {
            ll tot = 0;
            for (int i = 1; i <= n; i++) {
                tot += grids[i][cur_y];
            }
            grids[cur_x][cur_y] = -tot;
            cur_y++;
        }
    }
    ll tot = 0;
    for (int i = 1; i <= m; i++) {
        tot += grids[n][i];
    }
    grids[n][m] = -tot;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << grids[i][j] << " ";
        }
        cout << "\n";
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