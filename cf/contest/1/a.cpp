#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t n, m, a;
    std::cin >> n >> m >> a;
    std::cout << ((n + a - 1) / a) * ((m + a - 1) / a);
    return 0;
}
