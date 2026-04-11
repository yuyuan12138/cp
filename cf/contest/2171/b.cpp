#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    if (a[0] == -1 && a.back() == -1) {
        std::cout << 0 << '\n';
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) {
                a[i] = 0;
            }
            std::cout << a[i] << " \n"[i == n - 1];
        }
    } else if (a[0] == -1 || a.back() == -1) {
        std::cout << 0 << '\n';
        if (a[0] == -1) {
            a[0] = a.back();
        } else {
            a.back() = a[0];
        }
        for (int i = 0; i < n; i++) {
            std::cout << (a[i] >= 0 ? a[i] : 0) << " \n"[i == n - 1];
        }
    } else {
        std::cout << std::abs(a[0] - a.back()) << '\n';
        for (int i = 0; i < n; i++) {
            std::cout << (a[i] >= 0 ? a[i] : 0) << " \n"[i == n - 1];
        }
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
}
