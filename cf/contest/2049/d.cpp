#include <bits/stdc++.h>

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<int>> s(n, std::vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> s[i][j];
        }
    }
    std::vector<std::vector<int>> f(n, std::vector<int> (m));
    auto get = [&](int x) -> int {
        
    };
    f[0][0] = s[0][0];
    for (int i = 1; i < m; i++) {
        f[0][i] += f[0][i - 1];
    }
    
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
