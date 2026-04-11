#include <bits/stdc++.h>

template <typename T>
void discretization(std::vector<T>& a) {
    const int n = a.size();
    std::vector<T> tmp(a);  
    std::sort(tmp.begin(), tmp.end());
    tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());
    for (int i = 0; i < n; i++) {
        a[i] = std::lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin();
    }
}

constexpr int inf = 1e9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }
    discretization(x);
    discretization(y);
    std::vector<std::vector<int>> s(n + 1, std::vector<int> (n + 1));
    for (int i = 0; i < n; i++) {
        s[x[i] + 1][y[i] + 1] = 1;

    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    int ans = inf;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans = std::min(ans, std::max({s[i][j], s[i][n] - s[i][j], s[n][j] - s[i][j], s[n][n] + s[i][j] - s[n][j] - s[i][n]}));
        }
    }
    std::cout << ans;
    return 0;
}
