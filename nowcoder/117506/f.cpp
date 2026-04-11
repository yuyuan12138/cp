#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 n, m, p, x, a, b, c;
    std::cin >> n >> m >> p >> x >> a >> b >> c;
    std::map<i64, int> mp;
    i64 ans = 0;
    for (int i = 0; i < n + m; i++) {
        x = a % p * x % p * x % p + b % p * x % p + c % p;
        x %= p;
        if (i < n) {
            if (!mp.count(x)) {
                mp[x] = i;
            }
        } else {
            if (mp.count(x)) {
                ans = std::max(ans, std::min(i64(m) - i + n, i64(n) - mp[x]));
            }
        }
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
