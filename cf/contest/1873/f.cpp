#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), h(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> h[i];
    }
    int ans = 0;
    for (int i = 0, j = 1; i < n; i = j++) {
        while (j < n && (h[j - 1] % h[j] == 0)) {
            j++;
        }
        int sum = 0;
        // std::cerr << "(" << i << " " << j << ")\n";
        for (int x = i, y = i; x < j; x++) {
            while (y < j && sum + a[y] <= k) {
                sum += a[y];
                y++;
            }
            ans = std::max(ans, y - x);
            sum -= a[x];
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
