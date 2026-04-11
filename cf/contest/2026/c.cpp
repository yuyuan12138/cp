/**
 *      author:  yuyuan567
 *      created: 2025-08-21 13:59:54
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
        std::string s;
        std::cin >> s;
        std::vector<int> costs(n);
        std::iota(costs.begin(), costs.end(), 1);
        int64_t ans = int64_t(n + 1) * n / 2;
        std::vector<int> free_idx;
        std::stack<int> buy_idx;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                buy_idx.push(i);
            } else {
                free_idx.push_back(i);
            }
        }
        int sz = free_idx.size();
        int cur = 0;
        for (int i = sz - 1; i >= cur; i--) {
            while (!buy_idx.empty() && buy_idx.top() >= free_idx[i]) {
                buy_idx.pop(); 
            }
            if (!buy_idx.empty()) {
                buy_idx.pop();
                ans -= int64_t(costs[free_idx[i]]);
            } else if (i != cur) {
                cur ++;
                ans -= int64_t(costs[free_idx[i]]);
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}
