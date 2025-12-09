#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n;
        std::cin >> n;
        std::vector<int> freqs(n + 1);
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            freqs[x]++;
        }
        int mn = INT32_MAX;
        int cnt = 0;
        int ans = 0;
        std::sort(freqs.begin(), freqs.end(), std::greater<int>());
        for (int i = 0; i <= n; i++) {
            if (freqs[i] != 0) {
                cnt++;
                mn = std::min(mn, freqs[i]);
            }
            ans = std::max(ans, cnt * mn);
            std::cerr << ans << '\n';
        }
        std::cout << ans << '\n';
    }
    return 0;
}
