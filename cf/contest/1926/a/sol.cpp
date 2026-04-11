/**
 *      author:  yuyuan567
 *      created: 2025-08-23 00:06:26
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
        std::string s;
        std::cin >> s;
        int cnt0 = 0;
        for (auto c: s) {
            if (c == 'A')
                cnt0++;
        } 
        std::cout << (2 * cnt0 > s.size() ? 'A' : 'B') << '\n';
    }
    return 0;
}
