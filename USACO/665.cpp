#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    std::vector<std::string> res(n * k, std::string(m * k, '?'));
    for (int i = 0; i < n * k; i++) {
        for (int j = 0; j < m * k; j++) {
            res[i][j] = s[i / k][j / k];
        }
    }
    for (int i = 0; i < n * k; i++) {
        std::cout << res[i] << '\n';
    }
    return 0;
}
