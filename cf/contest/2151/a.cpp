#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(m);
    int mx = 0;
    for (int i = 0; i < m; i++) {
        std::cin >> a[i];
        mx = std::max(mx, a[i]);
    }
    bool ok = false;
    for (int i = 1; i < m; i++) {
        if (a[i] <= a[i - 1]) {
            ok = true;
        }
    }
    if (ok) {
        std::cout << 1 << '\n';
    } else {
        std::cout << n - mx + 1 << '\n';
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
