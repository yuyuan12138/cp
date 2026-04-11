/**
 *      author:  yuyuan567
 *      created: 2025-08-30 20:08:34
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
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<char> vec;
    int64_t ans = 0;
    int cur = 1;
    for (int i = 0; i < 2 * n; i++) {
        if (s[i] != s[0]) {
            ans += std::abs(cur - i);
            cur += 2;
        }
    }
    int64_t ans2 = 0;
    cur = 1;
    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == s[0]) {
            ans2 += std::abs(cur - i);
            cur += 2;
        }
    }
    debug(vec);
    std::cout << std::min(ans, ans2);
    return 0;
}
