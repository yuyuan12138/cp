#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> cnt(3);
    for (int i = 0, x; i < n; i++) {
        std::cin >> x;
        cnt[x]++;
    }
    int ans = cnt[0];
    int t = std::min(cnt[1], cnt[2]);
    ans += t;
    cnt[1] -= t;
    cnt[2] -= t;
    cnt[1] = std::max(0, cnt[1]);
    cnt[2] = std::max(0, cnt[2]);
    std::cout << ans + cnt[1] / 3 + cnt[2] / 3 << '\n';
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
