#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        mp[x]++;
    }
    i64 ans = i64(mp[2] + mp[1]) * (mp[2] + mp[1] - 1) / 2;
    ans = std::max(0ll, ans);

    for (auto [val, cnt] : mp) {
        if (val != 1 && val != 2) {
            ans += i64(cnt) * (cnt - 1) / 2;
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