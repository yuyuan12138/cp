/**
 *    author:  Yuyuan
 *    created: 2026-04-18 15:28:02
 **/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::multiset<i64> st;
    for (int i = 0, x; i < n; i++) {
        std::cin >> x;
        st.insert(x);
    }
    std::vector<i64> ans(2);
    bool who = false;
    while (!st.empty()) {
        i64 tot = ans[who];
        auto it = st.upper_bound(tot);
        if (it != st.begin()) {
            it = std::prev(it);
        }
        ans[who] += *it;
        st.erase(it);
        who ^= 1;
    }
    std::cout << ans[0] << ' ' << ans[1];
    return 0;
}
