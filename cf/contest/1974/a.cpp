#include <bits/stdc++.h>

void solve() {
    int x, y;
    std::cin >> x >> y;
    int a = (y + 1) / 2;
    int b = (x + 6) / 7;
    if (b <= a) {
        std::cout << a << '\n';
    } else if (y % 2) {
        x -= a * 7;
        x -= 4;
        if (x <= 0) {
            std::cout << a << '\n';
        } else {
            std::cout << a + (x + 14) / 15 << '\n';
        }
    } else {
        x -= a * 7;
        std::cout << a + (x + 14) / 15 << '\n';
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
