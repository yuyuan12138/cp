#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    bool ok = false;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] <= 0) {
            ok = true;
        }
    }
    if (n == 1) {
        std::cout << a[0];
        return 0;
    }
    std::sort(a.begin(), a.end());
    i64 ans = a[n - 1];
    if (ok) {
        for (int i = 0; i < n - 1; i++) {
            ans += 1ll * std::abs(a[i]);
        }
    } else {
        for (int i = 1; i < n - 1; i++) {
            ans += 1ll * std::abs(a[i]);
        }
        ans -= a[0];
    }
    std::cout << ans;
    return 0;
}