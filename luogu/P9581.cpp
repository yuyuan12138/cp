#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a, b;
    std::cin >> a >> b;
    if (a * b <= 0) {
        int min = std::min(std::abs(a), std::abs(b));
        int max = std::max(std::abs(a), std::abs(b));
        std::cout << min * 2 + max;
    } else {
        std::cout << std::max(std::abs(a), std::abs(b));
    }
    return 0;
}
