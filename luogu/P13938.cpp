#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    auto get = [](const int x, const int y) -> i64 {
        return i64(x) * y * 2 + i64(x) + i64(y);
    };

    i64 ans = 0;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= m + 1; j++) {
            int x = std::min(i - 1, n + 1 - i);
            int y = std::min(j - 1, m + 1 - j);
            ans += get(x, y);
        }
    }
    std::cout << ans;
    return 0;
}

