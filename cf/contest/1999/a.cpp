/**
 *      author:  yuyuan567
 *      created: 2025-08-16 00:46:17
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

    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int tt;
    std::cin >> tt;
    while (tt--) {
        std::string s;
        std::cin >> s;
        int a = s[0] - '0';
        int b = s[1] - '0';
        std::cout << a + b << '\n';
    }
    return 0;
}
