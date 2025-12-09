#include <bits/stdc++.h>

constexpr int inf = 1e9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::freopen("cbarn.in", "r", stdin);
    std::freopen("cbarn.out", "w", stdout);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int tot = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        cur += a[i] * i;
        tot += a[i];
    }
    int ans = inf;
    for (int i = 0; i < n; i++) {
        cur += n * a[i] - tot;
        ans = std::min(ans, cur);
    }
    std::cout << ans;
    return 0;
}