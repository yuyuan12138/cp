/**
 *      author:  yuyuan567
 *      created: 2025-09-01 09:05:58
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
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    bool ok = false;
    for (int i = 1; i < n - 1; i++) {
        if (a[i - 1] + a[i] > a[i + 1]) {
            ok = true;
        }
    }
    std::cout << (ok ? "YES\n" : "NO\n");
    return 0;
}
