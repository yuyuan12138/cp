#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

using i64 = long long;
#define ordered_set                                                            \
    tree<std::pair<i64, size_t>, null_type, std::less<std::pair<i64, size_t>>, \
         rb_tree_tag, tree_order_statistics_node_update>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    ordered_set st1, st2;
    i64 sum1 = 0, sum2 = 0;
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sum1 += a[i];
            i64 tot = -sum1 + sum2;
            ans += st2.size() - st2.order_of_key({tot + 1, 0});
            st1.insert({sum1 - sum2, i});
            ans += (tot < 0);
        } else {
            sum2 += a[i];
            i64 tot = -sum1 + sum2;
            ans += st1.size() - st1.order_of_key({-tot + 1, 0});
            st2.insert({sum2 - sum1, i});
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
