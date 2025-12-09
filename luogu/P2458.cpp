#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e15;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    std::cin >> n;
    vector<ll> cost(n + 1);
    vector<vector<int>> children(n + 1);
    vector<int> is_root(n + 1, 1);

    for (int i = 0; i < n; ++i) {
        int u, k, m;
        cin >> u >> k >> m;
        cost[u] = k;
        for (int j = 0; j < m; ++j) {
            int v; cin >> v;
            children[u].push_back(v);
            is_root[v] = 0;
        }
    }

    int root = 1;
    for (int i = 1; i <= n; ++i) if (is_root[i]) { root = i; break; }

    vector<array<ll,3>> dp(n + 1); // dp[u][0], dp[u][1], dp[u][2]

    auto dfs = [&](this auto&& dfs, int u) -> void {
        if (children[u].empty()) {
            dp[u][0] = cost[u];
            dp[u][1] = INF; // cannot be covered by child if no child
            dp[u][2] = 0;   // if parent covers u, no extra cost
            return;
        }

        // 初始化累加值
        ll sum_min012 = 0; // for dp0: sum min(dp0,dp1,dp2)
        ll sum_min01  = 0; // for dp2: sum min(dp0,dp1)
        ll sum_min01_for_dp1 = 0; // base sum for dp1: sum min(dp0,dp1)
        vector<ll> diff; diff.reserve(children[u].size());

        for (int v : children[u]) {
            dfs(v);
            ll m012 = min({dp[v][0], dp[v][1], dp[v][2]});
            sum_min012 += m012;
            ll m01 = min(dp[v][0], dp[v][1]);
            sum_min01 += m01;
            sum_min01_for_dp1 += m01;
            diff.push_back(dp[v][0] - m01); // extra cost if we force v to be chosen
        }

        // dp0: u chosen
        dp[u][0] = cost[u] + sum_min012;

        // dp2: u not chosen, rely on parent => children can't rely on u, so choose min(dp0,dp1)
        dp[u][2] = sum_min01;

        // dp1: u not chosen, must be covered by at least one child -> pick one child to be dp0
        // dp1 = sum_min01_for_dp1 + min_v (dp[v][0] - min(dp[v][0], dp[v][1])) 
        ll best_extra = INF;
        for (ll d : diff) if (d < best_extra) best_extra = d;
        if (best_extra == INF) dp[u][1] = INF; 
        else dp[u][1] = sum_min01_for_dp1 + best_extra;

        dp[u][0] = min(dp[u][0], INF);
        dp[u][1] = min(dp[u][1], INF);
        dp[u][2] = min(dp[u][2], INF);
    };

    dfs(root);
    ll ans = min(dp[root][0], dp[root][1]);
    cout << ans << "\n";
    return 0;
}
