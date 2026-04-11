/**
 *      author:  yuyuan567
 *      created: 2025-07-31 00:13:26
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
    int n, d, k;
    cin >> n >> d >> k;
    // vector<int> diff(n + 2);
    vector<vector<int>> cnt(n + 1, vector<int>(3));
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        cnt[l][1]++;
        cnt[r][2]++;
    }

    int tot = 0;
    for (int i = 1; i <= d; i++) {
        tot += cnt[i][1];
    }
    int cur_min = tot, cur_max = tot;
    int ans_min = 1, ans_max = 1;
    for (int i = d + 1; i <= n; i++) {
        tot += cnt[i][1];
        tot -= cnt[i - d][2];
        if (tot > cur_max) {
            cur_max = tot;
            ans_max = i - d + 1;
        }
        if (tot < cur_min) {
            cur_min = tot;
            ans_min = i - d + 1;
        }
    }
    cout << ans_max << " " << ans_min << "\n";

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