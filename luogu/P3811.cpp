#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, p;
    std::cin >> n >> p;
    
    std::vector<int> inv(n + 1);
    inv[1] = 1;
    std::cout << inv[1] << '\n';
    
    for (int i = 2; i <= n; i++) {
        inv[i] = (p - (i64)(p / i) * inv[p % i] % p) % p;
        std::cout << inv[i] << '\n';
    }
    
    return 0;
}