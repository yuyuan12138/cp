#include <bits/stdc++.h>

using i64 = long long;

int query(int i, int j) {
    int x;
    std::cout << "? " << i << ' ' << j << std::endl;
    std::cin >> x;
    return x;
}

void solve() {
    int n;
    std::cin >> n;
    for (int i = 3; i <= 2 * n - 1; i += 2) {
        int x = query(i, i + 1);
        if (x) {
            std::cout << "! " << i << std::endl;
            return ;
        }
    }
    if (query(1, 3) || query(1, 4)) {
        std::cout << "! " << 1 << std::endl;
    } else {
        std::cout << "! " << 2 << std::endl;
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
