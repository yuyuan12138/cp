#include <bits/stdc++.h>

void solve() {
    std::string s;
    std::cin >> s;
    if (s[1] >= '1' && s[1] <= '9') {
        int cnt = 0;
        int idx = 1;
        while (s[idx] >= '1' && s[idx] <= '9') {
            cnt = cnt * 10 + (s[idx] - '0');
            idx++;
        }
        idx++;
        int cnt2 = 0;
        while (s[idx] >= '1' && s[idx] <= '9') {
            cnt2 = cnt2 * 10 + (s[idx] - '0');
            idx++;
        }
        std::string col = "";
        while (cnt2) {
            int div = cnt2 % 27;
            col += char(div + int('A'));
            cnt2 /= 27;
        }
        std::cout << col << cnt << '\n';
    } else {
        int idx = 0;
        int cnt = 0;
        while (s[idx] >= 'A' && s[idx] <= 'Z') {
            cnt = cnt * 26 + (s[idx] - 'A' + 1);
            idx++;
        }
        int cnt2 = 0;
        while (idx < s.size()) {
            cnt2 = cnt2 * 10 + (s[idx] - '0');
            idx++;
        }
        std::cout << "R" << cnt2 << "C" << cnt << '\n';
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
