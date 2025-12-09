#include <bits/stdc++.h>

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int ans = 0;
    int max = 0;
    max = a[0];
    if (a[1] <= a[0]) {
        ans++;
    }
    max = std::max(max, a[1]);
    for (int i = 2; i < n; i++) {
        if (i % 2 == 0) {
            if (a[i] >= max) {
                ans += a[i] - max + 1;
            }
        }
        max = std::max(max, a[i]);
    }
    std::cout << ans << '\n';
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t; 
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
