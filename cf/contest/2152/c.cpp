#include <bits/stdc++.h>

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<std::array<int, 2>> pref_sum(n);
    std::vector<int> pref_cnt(n);
    if (a[0] == 0) {
        pref_sum[0][0]++;
    } else {
        pref_sum[0][1]++;
    }
    for (int i = 1; i < n; i++) {
        pref_sum[i][1] = pref_sum[i - 1][1];
        pref_sum[i][0] = pref_sum[i - 1][0];
        if (a[i] == 1) {
            pref_sum[i][1] = pref_sum[i - 1][1] + 1;
        } else {
            pref_sum[i][0] = pref_sum[i - 1][0] + 1;
        }
    }
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            pref_cnt[i]++;
        }
    }
    for (int i = 1; i < n; i++) {
        pref_cnt[i] += pref_cnt[i - 1];
    }
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        l--, r--;
        if (l == 0) {
            if (pref_sum[r][0] % 3 != 0 || pref_sum[r][1] % 3 != 0) {
                std::cout << -1 << '\n';
            } else {
                std::cout << pref_sum[r][0] / 3 + pref_sum[r][1] / 3 +
                                 (pref_cnt[r] - pref_cnt[l] == 0)
                          << '\n';
            }
        } else {
            if ((pref_sum[r][0] - pref_sum[l - 1][0]) % 3 != 0 ||
                (pref_sum[r][1] - pref_sum[l - 1][1]) % 3 != 0) {
                std::cout << -1 << '\n';
            } else {
                std::cout << (pref_sum[r][0] - pref_sum[l - 1][0]) / 3 +
                                 (pref_sum[r][1] - pref_sum[l - 1][1]) / 3 +
                                 (pref_cnt[r] - pref_cnt[l] == 0)
                          << '\n';
            }
        }
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
