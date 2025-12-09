#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    if (n == 1) {
        std::cout << 1 << '\n';
    } else {
        int g = 0;
        for (int i = 1; i < n; i++) {
            g = std::gcd(g, a[i] - a[i - 1]);
        }
        int mx = *max_element(a.begin(), a.end());
        i64 ans = 0;
        std::vector<int> cnt(n + 1);
        for (int i = 0; i < n; i++) {
            a[i] = (mx - a[i]) / g;
            if (a[i] <= n) {
                cnt[a[i]]++;
            }
            ans += a[i];
        }
        int mex = 0;
        while (mex <= n && cnt[mex]) {
            mex++;
        }
        ans += mex;
        std::cout << ans << '\n';
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
