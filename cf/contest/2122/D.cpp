/**
 *      author:  yuyuan567
 *      created: 2025-07-29 12:35:51
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

constexpr int INF = 0x3f3f3f3f;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n + 1);
    vector<int> deg(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    vector<int> dp(n + 1, INF);
    dp[1] = 0;

    for (int t = 0;; t++) {
        if (dp[n] < INF) {
            debug(dp);
            cout << t << " " << dp[n] << "\n";
            return;
        }
        vector<int> new_dp(n + 1, INF);
        // new_dp.assign(all(dp));

        for (int v = 1; v <= n; v++) {
            new_dp[edges[v][t % deg[v]]] = min(dp[v], new_dp[edges[v][t % deg[v]]]);
        }
        for (int v = 1; v <= n; v++) {
            dp[v] = min(new_dp[v], dp[v] + 1);
        }

        // dp.assign(all(new_dp));
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