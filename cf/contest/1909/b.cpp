#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= 60; i++) {
        i64 x = (1ll << i);
        std::set<i64> st;
        for (int j = 0; j < n; j++) {
            st.insert(a[j] % x);
        }
        if (st.size() == 2) {
            std::cout << x << '\n';
            return;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
