/**
 *      author:  yuyuan567
 *      created: 2025-08-30 20:00:24
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
    std::map<std::string, std::set<int>> mp;
    for (int i = 1; i <= n; i++) {
        std::string s;
        std::cin >> s;
        mp[s].insert(i);
    }
    int x;
    std::string s;
    std::cin >> x >> s;
    std::cout << (mp[s].contains(x) ? "Yes\n" : "No\n");
    return 0;
}
