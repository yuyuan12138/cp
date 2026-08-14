#include <bits/stdc++.h>

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    for (int i = n - 1; i >= 1; i--) {
        int del = std::max(a[i] - b[i], 0ll);
        a[i] -= del;
        a[i - 1] += del;
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            ok = false;
        }
    }
    std::cout << (ok ? "YES\n" : "NO\n");
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
