/**
 *      author:  yuyuan567
 *      created: 2025-08-30 12:53:52
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
template <typename T, typename C = std::less<>>
using ordered_set = __gnu_pbds::
    tree<T, __gnu_pbds::null_type, C, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

// order_of_key(num), find_by_order(key)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n;
        std::cin >> n;
        struct Node {
            int l, r;
        };
        std::vector<Node> nodes(n);
        for (int i = 0; i < n; i++) {
            std::cin >> nodes[i].l >> nodes[i].r;
        }
        std::sort(nodes.begin(), nodes.end(), [](const Node& a, const Node& b) -> bool { return a.r < b.r; });
        ordered_set<int> st;
        int64_t ans = 0;
        for (int i = 0; i < n; i++) {
            ans += st.size() - st.order_of_key(nodes[i].l);
            st.insert(nodes[i].l);
        }
        std::cout << ans << '\n';
    }
    return 0;
}
