#include <bits/stdc++.h>

using i64 = long long;

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    std::vector<int> a(n);
    a[0] = 1;
    int cur = 2;
    for (i64 i = 1; i < n; i++) {
        i64 cnt = b[i] - b[i - 1];
        if (cnt == i + 1) {
            a[i] = i + 1;
        } else {
            a[i] = a[i - cnt];
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}