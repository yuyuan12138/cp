#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    int cnt = 0;
    int ans = 0;
    for (int i = 0, x; i < n; i++) {
        std::cin >> x;
        if (x == 0) {
            ans++;
        }
        if (x == -1) {
            cnt++;
        }
    }
    if (cnt % 2 == 0) {
        std::cout << ans << '\n';
    } else {
        std::cout << ans + 2 << '\n';
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
