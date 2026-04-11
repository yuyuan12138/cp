/**
 *      author:  yuyuan567
 *      created: 2025-08-24 22:37:02
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
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        bool ok = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && a[i] == a[j]) {
                    
                    ok = true;
                }
            }
        }
        std::cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
