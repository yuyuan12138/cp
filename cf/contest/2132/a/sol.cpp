/**
 *      author:  yuyuan567
 *      created: 2025-08-21 22:41:24
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
        int m;
        std::cin >> m;
        std::string a, b;
        std::cin >> a >> b;
        for (int i = 0; i < m; i++) {
            if (b[i] == 'D') {
                s = s + a[0];
                a.erase(a.begin());
            } else {
                s = a[0] + s;
                a.erase(a.begin());
            }
        }
        std::cout << s << '\n';
    }
    return 0;
}
