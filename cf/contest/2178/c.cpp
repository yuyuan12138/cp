#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 1e18;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n); 
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<std::array<i64, 2>> f(n, {-inf, -inf});
    f[0][0] = a[0];
    f[0][1] = 0;
    for (int i = 1; i < n; i++) {
        f[i][1] = std::max(f[i - 1][0], f[i - 1][1] - a[i]);
        f[i][0] = f[i - 1][0] + std::abs(a[i]);
    }
    std::cout << f[n - 1][1] << '\n';
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