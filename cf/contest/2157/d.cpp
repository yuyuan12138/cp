#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, l, r;
    std::cin >> n >> l >> r;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    i64 ans = 0;
    int val = -1;
    if (n % 2 == 1) {
        val = a[n / 2];
    } else {
        val = (a[n / 2] + a[n / 2 - 1]) / 2;
    }
    val = std::max(val, l);
    val = std::min(val, r);
    for (int i = 0; i < n; i++) {
        ans += std::abs(a[i] - val);
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