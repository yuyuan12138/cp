/**
 *      author:  yuyuan567
 *      created: 2025-08-31 18:26:25
 */
#include <bits/stdc++.h>
#include <bits/stdc++.h>

void solve() {
    int n, x, y;
    std::cin >> n >> x >> y;
    x--, y--;
    std::vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = (i % 2 ? 1 : 0);
    }
    if (n % 2 == 0) {
        if (std::abs(y - x) > 1 && ans[y] == ans[x]) {
            ans[y] = 2;
        }
    } else {
        ans[x] = 2;
        int flag = 0;
        for (int i = x + 1; i < n; i++) {
            ans[i] = flag;
            flag ^= 1;
        }
        for (int i = 0; i < x; i++) {
            ans[i] = flag;
            flag ^= 1;
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t; 
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    return 0;
}
