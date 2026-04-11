#include <bits/stdc++.h>

void solve() {
    int n, s, m;
    std::cin >> n >> s >> m;
    std::vector<std::array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i][0] >> a[i][1];
    }
    bool ok = false;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (a[i][0] - cur >= s) {
            ok = true;
        }
        cur = a[i][1];
    } 
    if (m - a[n - 1][1] >= s) {
        ok = true;
    }
    std::cout << (ok ? "YES\n" : "NO\n");
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
