/**
 *      author:  yuyuan567
 *      created: 2025-08-06 21:12:29
 */
#include <bits/stdc++.h>


#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;

void solve(){
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::string> grids(n);
    for (int i = 0; i < n; i++) {
        std::cin >> grids[i];
    }

    // i * m + j;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    std::vector<int> dis(n * m, INT32_MAX);
    std::vector<bool> vis(n * m, false);
    dis[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [_, u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;

        int x = u / m, y = u % m;
        
        if (x > 0) {
            int tmp = 1;
            if (grids[x][y] == 'U') {
                tmp = 0;
            }
            if (dis[(x - 1) * m + y] > dis[x * m + y] + tmp) {
                dis[(x - 1) * m + y] = dis[x * m + y] + tmp;
                pq.push({dis[(x - 1) * m + y], (x - 1) * m + y});
            }
        }

        if (x < n - 1) {
            int tmp = 1;
            if (grids[x][y] == 'D') {
                tmp = 0;
            }
            if (dis[(x + 1) * m + y] > dis[x * m + y] + tmp) {
                dis[(x + 1) * m + y] = dis[x * m + y] + tmp;
                pq.push({dis[(x + 1) * m + y], (x + 1) * m + y});
            }
        }

        if (y > 0) {
            int tmp = 1;
            if (grids[x][y] == 'L') {
                tmp = 0;
            }
            if (dis[x * m + y - 1] > dis[x * m + y] + tmp) {
                dis[x * m + y - 1] = dis[x * m + y] + tmp;
                pq.push({dis[x * m + y - 1], x * m + y - 1});
            }
        }

        if (y < m - 1) {
            int tmp = 1;
            if (grids[x][y] == 'R') {
                tmp = 0;
            }
            if (dis[x * m + y + 1] > dis[x * m + y] + tmp) {
                dis[x * m + y + 1] = dis[x * m + y] + tmp;
                pq.push({dis[x * m + y + 1], x * m + y + 1});
            }
        }
    }

    if (dis[n * m - 1] <= k) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
    debug(dis);
    return ;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}