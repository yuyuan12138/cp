#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }
    i64 sum_a = a[n - 1], sum_b = b[m - 1];
    for (int i = n - 2; i >= 0; i--) {
        sum_a += a[i] - a[i + 1] + 1;
    }
    for (int i = m - 2; i >= 0; i--) {
        sum_b += b[i] - b[i + 1] + 1;
    }
    std::cout << (sum_a >= sum_b ? 1 : 2) << '\n';
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
