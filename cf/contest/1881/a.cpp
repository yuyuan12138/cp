#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::string s, t;
    std::cin >> s >> t;
    int ans = 0;
    while (s.find(t) == -1 && (ans == 0 || s.size() < 2 * m)) {
        s = s + s;
        ans++;
    }
    if (s.find(t) == -1) {
        std::cout << -1 << '\n';
    } else {
        std::cout << ans << '\n';
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