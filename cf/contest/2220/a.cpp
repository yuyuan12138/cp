/**
 *    author:  Yuyuan
 *    created: 2026-04-17 18:53:51
 **/
#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end(), std::greater<int>());
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i] == a[i - 1]) {
            ok = false;
        }
    }
    if (ok) {
        for (int i = 0; i < n; i++) {
            std::cout << a[i] << " \n"[i == n - 1];
        }
    } else {
        std::cout << -1 << '\n';
    }
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
