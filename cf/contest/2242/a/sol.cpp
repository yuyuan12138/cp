#include <bits/stdc++.h>

void solve() {
    int k;
    std::cin >> k;
    int cnt2 = 0;
    int cnt3 = 0;
    for (int i = 0, x; i < k; i++) {
        std::cin >> x;
        cnt3 += (x >= 3);
        cnt2 += (x >= 2);
    }
    std::cout << ((cnt3 >= 1 || cnt2 >= 2) ? "YES\n" : "NO\n");
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
