#include <bits/stdc++.h>

void solve() {
    std::vector<int> a(4);
    for (int i = 0; i < 4; i++) {
        std::cin >> a[i];
    }
    if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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
