#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<std::array<i64, 4>> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 3; j++) {
            pref[i][j] = pref[i - 1][j];
        }
        if (std::popcount(unsigned(a[i - 1])) == 1) {
            pref[i][0]++;
        } else if (std::popcount(unsigned(a[i - 1]) - 1) == 1) {
            pref[i][1]++;
        } else {
            pref[i][2]++;
        }
        pref[i][3] += (31 - std::countl_zero(unsigned(a[i - 1])));
    }
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        std::vector<i64> cnt(3);
        for (int i = 0; i < 3; i++) {
            cnt[i] = pref[r][i] - pref[l - 1][i];
        }
        i64 ans = pref[r][3] - pref[l - 1][3] + cnt[2] + cnt[1] / 2;
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
