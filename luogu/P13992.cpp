#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        std::string s;
        std::cin >> s;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                cnt++;
            }
        }
        std::cout << std::min(std::abs(5 - int(s.size())), std::abs(5 - cnt)) << '\n';
    }
    return 0;
}
