/**
 *      author:  yuyuan567
 *      created: 2025-08-24 12:05:21
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
        std::vector<int> a(n);
        int64_t tot = 0;
        int cur = 0;
        std::vector<int> cnt(n + 1);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            tot += a[i];
            cnt[a[i]]++;
            if (cnt[a[i]] >= 2 && a[i] > cur) {
                cur = a[i];
            }
            a[i] = cur;
        }
        std::fill(cnt.begin(), cnt.end(), 0);
        cur = 0;
        for (int i = 0; i < n; i++) {
            tot += a[i];
            cnt[a[i]]++;
            if (cnt[a[i]] >= 2 && a[i] > cur) {
                cur = a[i];
            }
            a[i] = cur;
        }
        std::fill(cnt.begin(), cnt.end(), 0);
        for (int i = 0; i < n; i++) {
            cnt[a[i]]++;
        }
        debug(a);
        debug(cnt);
        for (int i = 0; i < n; i++) {
            if (i < n - 1 && (a[i] == a[i + 1])) continue;
            if (cnt[a[i]] <= 1) {
                tot += a[i];
            } else {
                tot += int64_t(a[i]) * cnt[a[i]] * (n - i - 1) + int64_t(cnt[a[i]] + 1) * cnt[a[i]] * a[i] / 2;
            }
            debug(tot);
        } 
        std::cout << tot << '\n';
    }
    return 0;
}
