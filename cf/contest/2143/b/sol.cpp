#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), b(k);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < k; i++) {
        std::cin >> b[i];
    }
    std::sort(a.begin(), a.end(), std::greater<int>());
    std::sort(b.begin(), b.end());
    int64_t ans = std::accumulate(a.begin(), a.end(), 0LL);
    int cur = -1;
    for (int i = 0; i < k; i++) {
        cur += b[i];
        if (cur >= n) {
            break;
        } else {
            ans -= 1LL * a[cur];
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
