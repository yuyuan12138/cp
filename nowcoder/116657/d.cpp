#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> a, b;
    int x = -1;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        if (a.empty() || a.back().first != x) {
            a.emplace_back(x, 1);
        } else {
            a.back().second++;
        }
    }
    for (int i = 0; i < m; i++) {
        std::cin >> x;
        if (b.empty() || b.back().first != x) {
            b.emplace_back(x, 1);
        } else {
            b.back().second++;
        }
    }
    if (a.size() != b.size()) {
        std::cout << -1 << '\n';
    } else {
        n = a.size();
        bool ok = true;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i].second > b[i].second || a[i].first != b[i].first) {
                ok = false;
            } else {
                int x = a[i].second;
                int cnt = 0;
                while (x < b[i].second) {
                    x *= 2;
                    cnt++;
                }
                ans = std::max(ans, cnt);
            }
        }
        std::cout << (ok ? ans : -1) << '\n';
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
