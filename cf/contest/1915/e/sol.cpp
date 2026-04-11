/**
 *      author:  yuyuan567
 *      created: 2025-08-30 12:45:55
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
        std::vector<int64_t> pref(n + 1);
        int flag = -1;
        for (int i = 0; i < n; i++) {
            int64_t x;
            std::cin >> x;
            pref[i + 1] = pref[i] + x * flag;
            if (flag == -1) {
                flag = 1;
            } else {
                flag = -1;
            }
        }
        std::set<int64_t> st;
        st.insert(0LL);
        bool ok = false;
        for (int i = 1; i <= n; i++) {
            if (st.contains(pref[i])) {
                ok = true;
                break;
            } else {
                st.insert(pref[i]);
            }
        }
        debug(pref);
        std::cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
