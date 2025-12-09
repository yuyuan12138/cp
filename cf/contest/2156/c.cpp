#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> cnt(n + 2);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        cnt[x]++;
    }
    std::vector<int> pref(n + 2);
    for (int i = 0; i <= n; i++) {
        pref[i + 1] = cnt[i] + pref[i];
    }
    int ans = 1;
    for (int g = 1; g <= n; g++) {
        int tot = 0;
        tot += pref[std::min(4 * g, n + 1)];
        if (3 * g <= n) {
            tot -= cnt[3 * g];
        }
        if (2 * g <= n) {
            tot -= cnt[2 * g];
        }
        tot -= cnt[g];
        if (tot <= k) {
            ans = std::max(ans, g);
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