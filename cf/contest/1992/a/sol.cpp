/**
 *      author:  yuyuan567
 *      created: 2025-08-18 14:18:17
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
        std::multiset<int> st;
        for (int i = 0; i < 3; i++) {
            int x; std::cin >> x;
            st.insert(x);
        }
        for (int i = 0; i < 5; i++) {
            int x = *st.begin();
            st.erase(st.find(x));
            st.insert(x + 1);
        }
        int ans = 1;
        for (auto& x: st) {
            ans *= x;
        }
        std::cout << ans << '\n';
    }
    return 0;
}
