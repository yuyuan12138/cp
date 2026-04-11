/**
 *      author:  yuyuan567
 *      created: 2025-08-20 15:32:34
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> value(k + 1);
        for (int i = 0; i < k; i++) {
            int u, v;
            std::cin >> u >> v;
            value[u] += v;
        }
        std::sort(value.begin(), value.end());
        int ans = 0;
        for (int i = k, cnt = 0; cnt < n && i >= 0; i--, cnt++) {
            ans += value[i]; 
        }
        std::cout << ans << '\n';
    }
    return 0;
}
