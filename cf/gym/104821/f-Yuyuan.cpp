#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> last(m + 1);
    for (int i = 1; i <= n; i++) {
        int p;
        std::cin >> p;
        for (int j = 0; j < p; j++) {
            int pos;
            std::cin >> pos;
            last[pos] = i;
        }
    }
    std::set<int> st;
    for (int i = 1; i <= m; i++) {
        if (last[i] > 0) {
            st.insert(i);
        }
    }
    if (st.size())
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