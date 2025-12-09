#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    bool ok = true;
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (i > 0) {
            if (a[i] < a[i - 1]) {
                ok = false;
            }
        }
        ans += a[i];
    }
    if (ok || n == 1) {
        std::cout << ans << '\n';
    } else {
        std::sort(a.begin(), a.end());
        int64_t del = std::max(int64_t(0), int64_t(a[0]) + a[1] - m);
        std::cout << ans - del << '\n';
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
