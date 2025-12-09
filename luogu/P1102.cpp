#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t n, c;
    std::cin >> n >> c;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::map<int64_t, int64_t> mp;
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        mp[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        ans += mp[a[i] - c];
    }
    std::cout << ans;
    return 0;
}
