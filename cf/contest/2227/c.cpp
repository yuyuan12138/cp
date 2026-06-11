#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n), c(n);
    std::iota(c.begin(), c.end(), 0);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] % 2 == 0 && a[i] % 3 == 0) {
            b[i] = 0;
        } else if (a[i] % 2 == 0) {
            b[i] = 1;
        } else if (a[i] % 3 == 0) {
            b[i] = 3;
        } else {
            b[i] = 2;
        }
    }
    std::sort(c.begin(), c.end(),
              [&](const int i, const int j) -> bool { return b[i] < b[j]; });
    for (int i = 0; i < n; i++) {
        std::cout << a[c[i]] << " \n"[i == n - 1];
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
