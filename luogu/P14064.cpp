#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<int64_t> a(n), b(m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    if (n == m) {
        int64_t ans = 0;
        for (int i = 0; i < n; i++) {
            ans += std::abs(int64_t(a[i]) - b[i]);
        }
        std::cout << ans;
    } else {
        std::vector<std::vector<int64_t>> f(m, std::vector<int64_t> (2));
        f[0][0] = 0;
        f[0][1] = std::abs(a[0] - b[0]);
        for (int i = 1; i < m; i++) {
            f[i][0] = std::min(f[i - 1][1], f[i - 1][0] + std::abs(a[i - 1] - b[i]));
            f[i][1] = f[i - 1][1] + std::abs(a[i] - b[i]);
        }
        std::cout << f[m - 1][0];
    }

    return 0;
}
