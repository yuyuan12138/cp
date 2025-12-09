/**
 *      author:  yuyuan567
 *      created: 2025-08-23 00:21:29
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
    const int MAX = 200000;
    std::vector<int> digits_sum(MAX + 1);
    for (int i = 1; i <= MAX; i++) {
        digits_sum[i] = digits_sum[i / 10] + (i % 10);
    }
    std::vector<int64_t> pref(MAX + 1);
    for (int i = 1; i <= MAX; i++) {
        pref[i] = pref[i - 1] + digits_sum[i];
    }
    while (tt--) {
        int n;
        std::cin >> n;
        std::cout << pref[n] << '\n';
    }
    return 0;
}
