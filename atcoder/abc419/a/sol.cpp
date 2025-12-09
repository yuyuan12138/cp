/**
 *      author:  yuyuan567
 *      created: 2025-08-17 15:51:57
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
    std::string s;
    std::cin >> s;
    if (s == "red") {
        std::cout << "SSS";
    } else if (s == "blue") {
        std::cout << "FFF";
    } else if (s == "green") {
        std::cout << "MMM";
    } else {
        std::cout << "Unknown";
    }
    return 0;
}
