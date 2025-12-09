#include <bits/stdc++.h>

void solve() {
    int r0, x, d, n;
    std::cin >> r0 >> x >> d >> n;
    std::string s;
    std::cin >> s;
    int cur = r0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (cur < x || s[i] == '1') {
            ans++;
            cur = std::max(0, cur - d);
        }
    }
    std::cout << ans << '\n';
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
