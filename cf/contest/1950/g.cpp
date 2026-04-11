/**
 *      author:  yuyuan567
 *      created: 2025-08-10 15:31:00
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "../../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using namespace std;

using ll = long long;
using ull = unsigned long long;

class Graph {
public:
    int n;
    vector<vector<bool>> adj;

    Graph(int n) {
        this->n = n;
        adj.resize(n, vector<bool>(n, false));
    }

    int longest_hamiltonian_path() {
        int full_mask = (1 << n) - 1;
        vector<vector<bool>> dp(n, vector<bool>(full_mask + 1, false));
        for (int i = 0; i < n; i++) {
            dp[i][1 << i] = true;
        }

        for (int cnt = 0; cnt <= n; cnt++) {
            for (int mask = 0; mask <= full_mask; mask++) {
                if (__builtin_popcount(mask) != cnt) {
                    continue;
                }
                for (int i = 0; i < n; i++) {
                    if (((1 << i) & mask) == 0 || !dp[i][mask]) {
                        continue;
                    }
                    for (int k = 0; k < n; k++) {
                        if (adj[i][k] && ((1 << k) & mask) == 0) {
                            int nxt = mask | (1 << k);
                            dp[k][nxt] = true;
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int mask = 0; mask <= full_mask; mask++) {
                if (dp[i][mask]) {
                    ans = max(ans, __builtin_popcount(mask));
                }
            }
        }
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<string> g(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i] >> w[i];
    }

    Graph graph(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if ((g[i] == g[j]) || (w[i] == w[j])) {
                graph.adj[i][j] = true;
            }
        }
    }

    cout << n - graph.longest_hamiltonian_path() << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}