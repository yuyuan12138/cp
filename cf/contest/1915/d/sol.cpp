/**
 *      author:  yuyuan567
 *      created: 2025-08-30 12:24:42
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
        std::string res, s;
        std::cin >> s;
        auto check = [](const char x) -> bool {
            if (x == 'a' || x == 'e') {
                return true;
            } else {
                return false;
            }
        };
        while (!s.empty()) {
            int x;
            if (check(s.back())) {
                x = 2;
            } else {
                x = 3;
            }
            while (x--) {
                res += s.back();
                s.pop_back();
            }
            res += ".";
        }
        res.pop_back();
        std::reverse(res.begin(), res.end());
        std::cout << res << '\n';
    }
    return 0;
}
