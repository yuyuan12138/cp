#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> w(n), d(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i] >> d[i];
    }
    std::vector<int> f(m + 1);
    for (int i = 0; i < n; i++) {
        std::vector<int> nf = f;
        for (int j = m; j >= w[i]; j--) {
            nf[j] = std::max(f[j], f[j - w[i]] + d[i]);
        }
        f = std::move(nf);
    }
    int ans = 0;
    for (int i = 0; i <= m; i++) {
        ans = std::max(ans, f[i]);
    }
    std::cout << ans;
    return 0;
}