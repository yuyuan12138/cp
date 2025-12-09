/**
 *      author:  yuyuan567
 *      created: 2025-08-23 00:09:53
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
        int n;
        std::cin >> n;
        std::vector<std::string> grids(n);
        for (int i = 0; i < n; i++) {
            std::cin >> grids[i];
        }
        std::string ans;

        for (int i = 0; i < n; i++) {
            bool ok = true;
            for (int j = 0; j < n; j++) {
                if (grids[i][j] == '1') {
                    int cnt = 0;
                    int cnt_ = 0;

                    for (int k = i; k < n; k++) {
                        if (grids[k][j] == '1') cnt++;
                    }
                    for (int k = j; k < n; k++) {
                        if (grids[i][k] == '1') cnt_++;
                    }
                    ok = false;
                    if (cnt == cnt_) {
                        ans = "SQUARE";
                    } else {
                        ans = "TRIANGLE";
                    }
                    break;

                }
            }
            if (!ok) break;
        }
        std::cout << ans << '\n';
    }
    return 0;
}
