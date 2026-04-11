#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    int64_t cntu = 0, cntl = 0;
    auto get_dis = [](const int64_t x, const int64_t y) -> int64_t {
        return std::abs(x) + std::abs(y);
    };
    int64_t mx = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') {
            cntu++;
        } else if (s[i] == 'D') {
            cntu--;
        } else if (s[i] == 'L') {
            cntl++;
        } else {
            cntl--;
        }
        mx = std::max(mx, get_dis(-cntl, cntu));
    }
    int64_t x = int64_t(k - 1) * (-cntl);
    int64_t y = int64_t(k - 1) * cntu;
    mx = std::max(mx, std::abs(x) + std::abs(y));
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') {
            y++;
        } else if (s[i] == 'D') {
            y--;
        } else if (s[i] == 'L') {
            x--;
        } else {
            x++;
        }
        mx = std::max(mx, get_dis(x, y));
    }
    std::cout << mx << '\n';
} 

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt;
    std::cin >> tt;
    while (tt--)
        solve();
    return 0;
}
