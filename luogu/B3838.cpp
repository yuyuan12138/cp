#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    if (d >= b) {
        std::cout << (c - a) * 60 + (d - b);
    } else {
        std::cout << (c - a - 1) * 60 + (60 - b + d);
    }
}