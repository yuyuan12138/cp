/**
 *      author:  yuyuan567
 *      created: 2025-08-31 09:19:28
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
        int n, x;
        std::cin >> n >> x;
        std::vector<int> a(n);
        bool ok = false;
        bool is_same = false;
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            if (a[i] == x) {
                is_same = true;
            }
            if (a[i] != x) {
                ok = true;
            }
        }
        int tot = std::accumulate(a.begin(), a.end(), 0);
        if (!ok) {
            std::cout << "0\n";
        } else if (tot == x * n || is_same) {
            std::cout << "1\n";
        } else {
            std::cout << "2\n";
        }
    }
    return 0;
}
