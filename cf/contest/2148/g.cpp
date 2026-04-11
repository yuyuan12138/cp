#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    auto get_divs = [](const int x) -> std::vector<int> {
        std::vector<int> res;
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                res.push_back(i);
                if (i * i != x) {
                    res.push_back(x / i);
                }
            }
        }
        return res;
    };
    std::vector<int> cnt(n + 1);
    int ans = 0, g = 0;
    for (int i = 0; i < n; i++) {
        std::vector<int> divs = get_divs(a[i]);
        for (int div: divs) {
            cnt[div]++;
            if (cnt[div] != i + 1) {
                ans = std::max(ans, cnt[div]);
            }
        }
        if (std::gcd(g, a[i]) != g) {
            ans = std::max(ans, i);
        }
        g = std::gcd(g, a[i]);
        std::cout << ans << " \n"[i == n - 1];
    }
    
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
