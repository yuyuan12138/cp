#include <bits/stdc++.h>

constexpr int inf = 1e9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> vis(n, -1);

    auto solve = [&](auto&& self, int i) -> int {
        if (i == 0) {
            return 0;
        }
        if (i == 1) {
            return std::abs(a[1] - a[0]);
        }
        if (vis[i] != -1) {
            return vis[i];
        }
        int ans = std::min(self(self, i - 1) + std::abs(a[i] - a[i - 1]), self(self, i - 2) + std::abs(a[i] - a[i - 2]));
        vis[i] = ans;
        return ans;
    };
    std::cout << solve(solve, n - 1);
    return 0;
}
