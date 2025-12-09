/**
 *      author:  yuyuan567
 *      created: 2025-08-20 15:25:41
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n;
        std::cin >> n;
        bool ok = true;
        std::vector<int> a(n); 
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }


        for (int i = 1; i < n; i++) {
            if (std::abs(a[i] - a[i - 1]) == 5 || std::abs(a[i] - a[i - 1]) == 7) {
                continue;
            }
            ok = false;
        }
        
        std::cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
