#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    if (m > n + 1) {
        std::cout << "Yes\n";
    } else {
        bool ok = false;
        for (int j = 1; j <= m; j++) {
            if (n % j != (j - 1)) {
                ok = true;
            }
            if (ok) {
                break;
            }
        }
        std::cout << (ok ? "Yes\n" : "No\n");
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
