/**
 *    author:  Yuyuan
 *    created: 2026-04-17 18:59:05
 **/
#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int cnt = 1;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i] == a[i - 1]) {
            cnt++;
        } else {
            cnt = 1;
        }
        if (cnt >= m) {
            ok = false;
        }
    }
    std::cout << (ok ? "YES\n" : "NO\n");
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
