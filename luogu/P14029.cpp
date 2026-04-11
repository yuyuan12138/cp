#include <bits/stdc++.h>

struct Node {
    int val, idx;
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(n), ans(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i] %= m;
    }
    auto cmp = [](const Node& a, const Node& b) -> bool {
        return a.val == b.val ? a.idx < b.idx : a.val < b.val;
    };
    std::multiset<Node, decltype(cmp)> st(cmp);
    for (int i = 0, x; i < n; i++) {
        std::cin >> x;
        b[i] = x;
        x %= m;
        st.insert(Node{x, i});
    }
    int64_t sum = 0;
    for (int i = 0; i < n; i++) {
        auto it = st.lower_bound(Node{m - a[i], -1});
        if (it == st.begin()) {
            ans[i] = b[st.rbegin()->idx];
            st.erase(std::prev(st.end()));
        } else {
            it = std::prev(it);
            if (it->val + a[i] < m) {
                ans[i] = b[it->idx];
                st.erase(it);
            } else {
                ans[i] = b[st.rbegin()->idx];
                st.erase(std::prev(st.end()));
            }
        }
        sum += (ans[i] + a[i]) % m;
    }
    std::cout << sum << '\n';
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }

} 

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt;
    std::cin >> tt;
    while (tt--)
        solve();
    return 0;
}
