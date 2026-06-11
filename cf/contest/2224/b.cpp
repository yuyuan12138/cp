#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin() + 1, a.end());
    std::unique(a.begin() + 1, a.end());
    a[0] = a[n];
    int mex = 0;
    int max = 0;
    i64 ans = 0;

    std::vector<int> cnt(int(3e5));
    for (int i = 0; i < n; i++) {
        max = std::max(max, a[i]);
        if (a[i] < 3e5) {
            cnt[a[i]] = 1;
        }
        while (cnt[mex]) {
            mex++;
        }
        ans += max + mex;
    }
    std::cout << ans << '\n';
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
