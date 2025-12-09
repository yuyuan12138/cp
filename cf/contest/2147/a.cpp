#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int x, y;
        std::cin >> x >> y;
        if (x < y) {
            std::cout << "2\n";
        } else if (x > y && x - 1 > y && y > 1) {
            std::cout << "3\n";
        } else {
            std::cout << "-1\n";
        }
    }
    return 0;
}
