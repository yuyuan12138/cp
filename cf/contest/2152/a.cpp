#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::set<int> st;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        st.insert(x);
    }
    std::cout << (st.size() - 1) + st.size() << '\n';
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
