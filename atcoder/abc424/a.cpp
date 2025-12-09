#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a == b || a == c || b == c) {
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }
    return 0;
}
