/**
 *      author:  yuyuan567
 *      created: 2025-08-24 11:48:43
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
        int n; std::cin >> n;
        std::vector<int> cnt(n + 1);
        std::set<int> a;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            a.insert(x);
            cnt[x]++;
        }
        bool ok = false;
        while (!a.empty()) {
            int x = *a.rbegin();
            if (cnt[x] % 2) {
                ok = true;
                break;
            } else {
                a.erase(x);
            }
        }
        std::cout << (ok ? "YES\n" : "NO\n") ;
    }
    return 0;
}
