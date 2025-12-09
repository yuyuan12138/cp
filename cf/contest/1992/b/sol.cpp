/**
 *      author:  yuyuan567
 *      created: 2025-08-18 14:23:10
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
        int n, k;
        std::cin >> n >> k;
        std::multiset<int> st;
        for (int i = 0; i < k; i++) {
            int x;
            std::cin >> x;
            st.insert(x);
        }
        ll ans = 0;
        while (st.size() != 1) {
            int x = *st.begin();
            ans += 2 * (x - 1) + 1;
            st.erase(st.find(x));
        }
        std::cout << ans << '\n';
    }
    return 0;
}
