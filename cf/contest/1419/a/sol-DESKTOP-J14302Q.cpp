/**
 *      author:  yuyuan567
 *      created: 2025-08-31 08:58:18
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
        std::string s;
        std::cin >> s;
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0 && (s[i] - '0') % 2 == 1) {
                cnt1++;
            }
            if (i % 2 == 1 && (s[i] - '0') % 2 == 0) {
                cnt2++;
            }
        }
        if (n % 2 == 1) {
            std::cout << (cnt1 > 0 ? "1\n" : "2\n");
        } else {
            std::cout << (cnt2 > 0 ? "2\n" : "1\n");
        }
    }
    return 0;
}
