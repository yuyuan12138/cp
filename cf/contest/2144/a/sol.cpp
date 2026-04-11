#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
    }
    for (int l = 0; l < n - 1; l++) {
        for (int r = l + 1; r < n; r++) {
            if (((a[l] % 3) == (a[r] - a[l]) % 3 &&
                 (a[l] % 3) == (a[n - 1] - a[r]) % 3) ||
                (a[l] % 3 != (a[r] - a[l]) % 3 &&
                 (a[l] % 3) != ((a[n - 1] - a[r]) % 3) &&
                 (a[n - 1] - a[r]) % 3 != (a[r] - a[l]) % 3)) {
                std::cout << l + 1 << " " << r + 1 << "\n";
                return;
            }
        }
    }
    std::cout << "0 0\n";
}
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
