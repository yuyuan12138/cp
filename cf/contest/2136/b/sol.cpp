/**
 *      author:  yuyuan567
 *      created: 2025-08-29 14:04:19
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
        int n, k;
        std::cin >> n >> k;
        std::string s;
        std::cin >> s;
        bool ok = true;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cur++;
            } else {
                cur = 0;
            }
            if (cur >= k) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            std::cout << "NO\n";
        } else {
            cur = 1;
            std::vector<int> ans(n);
            for (int i = 0; i < n; i++) {
                if (s[i] == '1') {
                    ans[i] = cur;
                    cur++;
                }
            }
            for (int i = 0; i < n; i++) {
                if (s[i] == '0') {
                    ans[i] = cur;
                    cur++;
                }
            }
            std::cout << "YES\n";
            for (int i = 0; i < n; i++) {
                std::cout << ans[i] << " \n"[i == n - 1];
            }
        }
    }
    return 0;
}
