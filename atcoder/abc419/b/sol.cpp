/**
 *      author:  yuyuan567
 *      created: 2025-08-17 15:54:51
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
    int q;
    std::multiset<int> st;
    std::cin >> q;
    while (q--) {
        int op, x;
        std::cin >> op;
        if (op == 1) {
            std::cin >> x;
            st.insert(x);
        } else {
            std::cout << *st.begin() << '\n';
            st.erase(st.begin());
        }
    }
    return 0;
}
