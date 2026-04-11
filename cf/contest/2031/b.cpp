#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    bool ok = true;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != i + 1) {
            if ((i > 0 && a[i - 1] == i + 1) || (i < n - 1 && a[i + 1] == i + 1)) {
                continue;
            } else {
                ok = false;
            }
        }
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
