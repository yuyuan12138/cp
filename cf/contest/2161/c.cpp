#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, X;
    std::cin >> n >> X;
    std::vector<int> a(n);
    i64 tot = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        tot += a[i];
    }
    int cnt = tot / X;
    std::sort(a.begin(), a.end());
    i64 ans = 0;
    for (int i = 0; i < cnt; i++) {
        ans += a[n - 1 - i];
    }
    std::cout << ans << '\n';
    int l = 0, r = n - 1;
    i64 cur = 0;
    std::vector<int> b;
    while (l <= r) {
        if ((cur + a[r]) / X != cur / X) {
            b.push_back(a[r]);
            cur += a[r];
            r--;
        } else {
            b.push_back(a[l]);
            cur += a[l];
            l++;
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << b[i] << " \n"[i == n - 1];
    }
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
