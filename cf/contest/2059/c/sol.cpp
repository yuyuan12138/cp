#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector s(n, std::vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> s[i][j];
        }
    }
    std::vector<int> a;
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (s[i][j] == 1) {
                cur++;
            } else {
                break;
            }
        }
        if (cur) {
            a.push_back(cur);
        }
    }
    std::sort(a.begin(), a.end());
    int ans = 1;
    bool ok = false;
    for (int i = 0; i < a.size(); i++) {
        if (ans <= a[i]) {
            ans++;
        } else {
            ok = true;
        }
    }
    if (ok || a.size() < n) {
        std::cout << ans << '\n';
    } else {
        std::cout << std::max(std::min(ans, n), 1) << '\n';
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
