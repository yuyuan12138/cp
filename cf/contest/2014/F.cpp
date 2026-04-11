/**
 *      author:  yuyuan567
 *      created: 2025-07-31 16:11:44
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
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<vector<ll>> dp(n, vector<ll>(2));
    vector<bool> vis(n, false);
    [&](this auto&& self, int idx) -> void {
        // if (vis[idx])
        //     return;
        vis[idx] = true;
        dp[idx][0] = 0;
        dp[idx][1] = a[idx];

        for (auto j : graph[idx]) {
            if (vis[j])
                continue;
            self(j);
            dp[idx][0] += max(dp[j][0], dp[j][1]);
            dp[idx][1] += max(dp[j][0], dp[j][1] - 2 * c);
        }
    }(0);

    cout << max(dp[0][0], dp[0][1]) << "\n";

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