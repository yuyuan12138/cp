#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int cur = 0;
    int ans = 0;
    int slow = 0;
    for (int i = 0; i < n; i++) {
        cur += a[i];
        while (cur > k) {
            cur -= a[slow];
            slow++;
        }
        ans = std::max(i - slow + 1, ans);
    }
    std::cout << ans << '\n';
    return 0;
}
