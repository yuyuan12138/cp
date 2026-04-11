/**
 *      author:  yuyuan567
 *      created: 2025-11-18 19:00:53
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using i64 = long long;
using ull = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    if (c >= a && d < b) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }

    return 0;
}