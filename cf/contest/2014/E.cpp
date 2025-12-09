/**
 *      author:  yuyuan567
 *      created: 2025-07-31 15:35:12
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
    int n, m, h;
    cin >> n >> m >> h;
    vector<bool> horses(n);
    vector<vector<pair<int, ll>>> graph(n);
    for (int i = 0; i < h; i++) {
        int x;
        cin >> x;
        horses[--x] = 1;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }
    vector<vector<ll>> d1(n, vector<ll>(2, 1e18));
    vector<vector<ll>> d2(n, vector<ll>(2, 1e18));
    auto digikstra = [&](int idx, vector<vector<ll>>& d) {
        auto cmp = [&](auto& a, auto& b) {
            return make_pair(d[a.first][a.second], a) < make_pair(d[b.first][b.second], b);
        };
        set<pair<int, int>, decltype(cmp)> q(cmp);

        d[idx][0] = 0;
        q.insert({idx, 0});
        while (!q.empty()) {
            auto [curv, curh] = *q.begin();
            q.erase(q.begin());

            bool horse = (curh || horses[curv]);
            for (auto& [neighv, neighd] : graph[curv]) {
                ll dis = horse ? neighd / 2 : neighd;
                if (d[neighv][horse] > d[curv][curh] + dis) {
                    q.erase({neighv, horse});
                    d[neighv][horse] = d[curv][curh] + dis;
                    q.insert({neighv, horse});
                }
            }
        }
    };
    digikstra(0, d1);
    digikstra(n - 1, d2);
    ll ans = 1e18;
    auto get = [&](int a) { return max(min(d1[a][0], d1[a][1]), min(d2[a][0], d2[a][1])); };
    for (int i = 0; i < n; i++) {
        ans = min(ans, get(i));
    }
    cout << (ans == 1e18 ? -1 : ans) << "\n";
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