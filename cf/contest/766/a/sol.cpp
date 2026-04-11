/**
 *      author:  yuyuan567
 *      created: 2025-09-01 09:00:24
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
    std::string a, b;
    std::cin >> a >> b;
    if (a == b) {
        std::cout << "-1\n";
    } else {
        if (a.size() > b.size()) {
            std::cout << a.size() << '\n';
        } else if (a.size() < b.size()) {
            std::cout << b.size() << '\n';
        } else {
            std::cout << a.size() << '\n';
        }
    }
    return 0;
}
