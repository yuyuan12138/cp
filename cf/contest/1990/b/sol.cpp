/**
 *      author:  yuyuan567
 *      created: 2025-08-23 13:03:28
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
    while (tt--) {
        int n, x, y;
        std::cin >> n >> x >> y;
        std::vector<int> ans(n);
        for (int i = y - 1; i <= x - 1; i++) {
            ans[i] = 1;
        }
        int flag = -1;

        for (int i = x; i < n; i++) {
            ans[i] = flag;
            if (flag == 1) {
                flag = -1;
            } else {
                flag = 1;
            }
        }
        flag = -1;
        for (int i = y - 2; i >= 0; i--) {
            ans[i] = flag;
            if (flag == 1) {
                flag = -1;
            } else {
                flag = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            std::cout << ans[i] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
