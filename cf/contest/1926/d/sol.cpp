/**
 *      author:  yuyuan567
 *      created: 2025-08-23 00:48:28
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    int N = (1 << 31) - 1;
    while (tt--) {
        int n;
        std::cin >> n;
        std::multiset<int> vis;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            if (!vis.empty() && vis.count(N ^ x)) {
                vis.erase(vis.find(N ^ x));
                continue;
            } else {
                vis.insert(x);
                cnt++;
            }
        }
        std::cout << cnt << '\n';
    }
    return 0;
}
