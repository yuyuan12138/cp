#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    bool has_even = false, has_odd = false;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] % 2 == 0) {
            has_even = true;
        } else {
            has_odd = true;
        }
    }
    if (has_even && has_odd) {
        std::sort(a.begin(), a.end());
    }
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
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
