#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, x, y;
    std::cin >> n >> x >> y;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    i64 ans = 0;
    std::map<std::pair<int, int>, int> mp;
    for (int i = 0; i < n; i++) {
        ans += mp[{(x - a[i] % x) % x, a[i] % y}];
        mp[{a[i] % x, a[i] % y}]++;
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
