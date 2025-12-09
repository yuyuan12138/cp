/**
 *      author:  yuyuan567
 *      created: 2025-08-31 09:39:43
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
    std::multiset<int> st;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        st.insert(a[i]);
    }
    std::vector<int> ans(n);
    for (int i = 1; i < n - 1; i += 2) {
        ans[i] = *st.begin();
        st.erase(st.find(ans[i]));
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        debug(ans);
        if (ans[i] != 0)
            continue;
        int mx = 0;
        if (i > 0) {
            mx = std::max(mx, ans[i - 1]);
        }
        if (i < n - 1) {
            mx = std::max(mx, ans[i + 1]);
        }
        auto it = st.upper_bound(mx);
        if (it == st.end()) {
            ans[i] = *st.begin();
        } else {
            ans[i] = *it;
        }
        st.erase(st.find(ans[i]));
    }

    for (int i = 1; i < n - 1; i++) {
        if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1]) {
            cnt++;
        }
    }

    std::cout << cnt << '\n';
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
    return 0;
}
