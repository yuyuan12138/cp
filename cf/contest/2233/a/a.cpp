#include <bits/stdc++.h>

constexpr int inf = 1e9;

void solve() {
    int n, x, y, z;
    std::cin >> n >> x >> y >> z;
    int min = inf;
    min = std::min((n + x + y - 1) / (x + y), min);
    if (n <= x * z) {
        min = std::min((n + x - 1) / x, min);
    } else {
        int cnt = z;
        n -= x * z;
        cnt += (n + x + 10 * y - 1) / (x + 10 * y);
        min = std::min(cnt, min);
    }
    std::cout << min << '\n';
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
