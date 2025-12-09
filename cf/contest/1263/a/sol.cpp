/**
 *      author:  yuyuan567
 *      created: 2025-08-31 15:20:40
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
        int a, b, c;
        std::cin >> a >> b >> c;
        std::vector<int> vec = {a, b, c};
        std::sort(vec.begin(), vec.end());
        int del = vec[1] + vec[2] - vec[0];
        del /= 2;

        std::cout << std::min(vec[1], del) + vec[0] << '\n';
    }
    return 0;
}
