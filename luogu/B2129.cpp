#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(3);
    double a, b, c;
    std::cin >> a >> b >> c;
    std::cout << std::max({a, b, c}) / (std::max({a + b, b, c}) * std::max({a, b, b + c}));
    return 0;
}