#include <bits/stdc++.h>

constexpr int N = 2e5;

void solve() {
    int n, y;
    std::cin >> n >> y;
    std::vector<int> freqs(N + 1);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        freqs[x]++;
        mx = std::max(mx, x);
    }
    std::vector<int> pref(N + 1);
    for (int i = 1; i <= mx; i++) {
        pref[i] = pref[i - 1] + freqs[i];
    }
    if (mx == 1) {
        std::cout << n << '\n';
        return ;
    }
    int64_t ans = INT64_MIN;
    for (int x = 2; x <= mx; x++) {
        int64_t val = 0;
        for (int i = 1; i <= (mx + x - 1) / x; i++) {
            int l = (i - 1) * x + 1;
            int r = std::min(i * x, mx);
            int c = pref[r] - pref[l - 1];
            val += int64_t(i) * c;
            val -= int64_t(y) * std::max(0, c - freqs[i]);
        }
        ans = std::max(ans, val);
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
