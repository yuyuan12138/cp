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

    std::vector<std::vector<int>> vis(n, std::vector<int> (m));
    std::string ans = "";
    int stx, sty;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'A') {
                stx = i, sty = j;
            }
        }
    }

    

    return 0;
}