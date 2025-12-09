#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> freqs(m + 1);
    auto check = [&](std::vector<int>& b) {
        for (int x : b) {
            if (freqs[x] <= 1) {
                return false;
            }
        }
        return true;
    };
    std::set<int> st;

    std::vector<std::vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int y;
        std::cin >> y;
        for (int j = 0; j < y; j++) {
            int x;
            std::cin >> x;
            freqs[x]++;
            a[i].push_back(x);
            st.insert(x);
        }
    }
    if (st.size() < m) {
        std::cout << "NO\n";
        return;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (check(a[i])) {
            cnt++;
        }
    }
    std::cout << (cnt >= 2 ? "YES\n" : "NO\n");
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
