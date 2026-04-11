#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int m;
        std::cin >> m;
        for (int j = 0, x; j < m; j++) {
            std::cin >> x;
            a[i].push_back(x);
        }
    }
    std::vector<int> ans;
    int len = 0;
    while (true) {
        std::vector<int> v;
        for (int i = 0; i < n; i++) {
            if (a[i].size() > len) {
                std::vector x(a[i].begin() + len, a[i].end());
                if (v.empty() || x < v) {
                    v = x;
                }
            }
        }
        if (v.empty()) {
            break;
        }
        ans.insert(ans.end(), v.begin(), v.end());
        len = ans.size();
    }
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << " \n"[i == ans.size() - 1];
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