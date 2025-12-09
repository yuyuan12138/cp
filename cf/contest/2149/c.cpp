#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    std::vector<int> id(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        id[a[i]]++;
    } 
    int ans = 0;
    for (int i = 0; i < k; i++) {
        if (id[i] == 0) {
            ans++;
        }
    }
    ans += std::max(id[k] - ans, 0);
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
