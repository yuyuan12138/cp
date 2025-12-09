#include <bits/stdc++.h>

constexpr int N = 2025;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i * j == N) {
                ans = std::max(ans, 2 * i + 2 * j);
            }
        }
    }
    std::cout << ans;

    return 0;
}
