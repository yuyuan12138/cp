#include <bits/stdc++.h>

constexpr int inf = 1e9;

void solve() {
    int n;
    std::cin >> n;
    int max1 = -inf, max2 = -inf, min1 = inf, min2 = inf, max_x = -inf, min_x = inf, max_y = -inf, min_y = inf;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '#') {
                max1 = std::max(max1, i + j);
                max2 = std::max(max2, i - j);
                min1 = std::min(min1, i + j);
                min2 = std::min(min2, i - j);
                max_x = std::max(max_x, i);
                min_x = std::min(min_x, i);
                max_y = std::max(max_y, j);
                min_y = std::min(min_y, j);
            }
        }
    }
    if (max1 - min1 <= 1 || max2 - min2 <= 1 || (max_x - min_x <= 1 && max_y - min_y <= 1)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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
