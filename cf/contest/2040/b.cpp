#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    int cur = 1;
    int ans = 1;
    while (cur < n) {
        cur = (cur + 1) * 2;
        ans++;
    }
    std::cout << ans << '\n';
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
