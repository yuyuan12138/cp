#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int g = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        g = std::gcd(g, std::abs(a[i]));
    }
    std::cout << g;
    return 0;
}
