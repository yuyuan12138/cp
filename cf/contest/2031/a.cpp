/**
 *      author:  yuyuan567
 *      created: 2025-08-25 12:07:46
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
        std::vector<int> freq(n + 1);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            freq[x]++;
            cnt = std::max(cnt, freq[x]);
        }
        std::cout << n - cnt << '\n';
    }
    return 0;
}
