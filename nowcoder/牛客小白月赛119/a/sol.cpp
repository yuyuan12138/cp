/**
 *      author:  yuyuan567
 *      created: 2025-08-31 13:53:20
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
    int n = 5;
    int mx = 0;
    int tot = 0;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        mx = std::max(mx, x);
        tot += x;
    }
    tot += mx;
    int tot2 = 0;
    int mn = INT32_MAX;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        tot2 += x;
        mn = std::min(mn, x);
    }
    tot2 += mn;
    std::cout << (tot > tot2 ? "YES\n" : "NO\n");
    return 0;
}
