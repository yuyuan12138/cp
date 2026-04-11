#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int64_t> a(n + 1);
    int64_t ans = INT64_MIN;
    for (int i = 0; i < n; i++) {
        int64_t x;
        std::cin >> x;
        ans = std::max(ans, x);
        a[i + 1] = a[i] + x;
        ans = std::max(a[i + 1], ans);
    }
    int64_t mn = INT64_MAX;
    for (int i = 0; i < n; i++) {
        if (i >= 1) {
            ans = std::max(ans, a[i + 1] - mn);
        } else {
            ans = std::max(ans, a[i + 1]);
        }
        mn = std::min(mn, a[i + 1]);
    }
    std::cout << ans;
    return 0;
}
