#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    int idx = 0;
    std::vector<std::vector<int>> vis(n, std::vector<int> (m));
    auto dfs = [&](auto&& dfs, int i, int j) -> void {
        if (vis[i][j]) {
            return ;
        }
        vis[i][j] = 1;
        if (i < n - 1 && s[i + 1][j] == '.') {
            dfs(dfs, i + 1, j);
        }
        if (i > 0 && s[i - 1][j] == '.') {
            dfs(dfs, i - 1, j);
        }
        if (j > 0 && s[i][j - 1] == '.') {
            dfs(dfs, i, j - 1);
        }
        if (j < m - 1 && s[i][j + 1] == '.') {
            dfs(dfs, i, j + 1);
        }
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.' && !vis[i][j]) {
                dfs(dfs, i, j);
                idx++;
            }
        }
    }
    std::cout << idx;
}