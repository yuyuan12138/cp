#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << b + std::min(a, c);
    return 0;
}
