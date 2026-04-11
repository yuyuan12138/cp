/**
 *      author:  yuyuan567
 *      created: 2025-08-10 23:50:23
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "../../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> edges(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    if (n == 2) {
        std::cout << "0\n";
    } else {
        int cnt_leaf = 0;
        std::vector<int> freq(n);
        for (int i = 0; i < n; i++) {
            if (edges[i].size() == 1) {
                cnt_leaf++;
                freq[edges[i][0]]++;
            }
        }
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = std::max(mx, freq[i]);
        }
        std::cout << cnt_leaf - mx << "\n";
    }
    return;
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