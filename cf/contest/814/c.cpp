#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<std::map<char, int>> mp(n + 1);
    for (int m = 1; m <= n; m++) {
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int cnt = 0;
            int res = 0;
            for (int i = 0, j = 0; i < n; i++) {
                while (j < n) {
                    if (cnt == m && s[j] != ch) {
                        break;
                    }
                    if (cnt < m && s[j] != ch) {
                        cnt++;
                    }
                    j++;
                }
                res = std::max(res, j - i);
                if (s[i] != ch) {
                    cnt--;
                }
            }
            mp[m][ch] = res;
        }
    }
    int q;
    std::cin >> q;
    while (q--) {
        int x;
        char c;
        std::cin >> x >> c;
        std::cout << mp[x][c] << "\n";
    }
    return 0;
}
