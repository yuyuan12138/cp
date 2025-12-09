/**
 *      author:  yuyuan567
 *      created: 2025-08-25 10:55:59
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
    std::string s;
    int x;
    std::vector<std::pair<int, std::string>> ups, downs;
    int cnt = 0;
    while ((std::cin >> s >> x)) {
        if (cnt == 4) {
            downs.emplace_back(x, s);
        } else {
            cnt++;
            ups.emplace_back(x, s);
        }
    }
    auto cmp = [](std::pair<int, std::string>& a, std::pair<int, std::string>& b) {
        return a.first < b.first;
    };
    std::sort(ups.begin(), ups.end(), cmp);
    std::sort(downs.begin(), downs.end(), cmp);

    auto [mx1, ans1] = ups.back();
    auto [mx2, ans2] = downs.back();
    
    if (mx1 > mx2) {
        std::cout << ans1 << " beats " << ans2;
    } else {
        std::cout << ans2 << " beats " << ans1;
    }
    return 0;
}
