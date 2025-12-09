#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int k;
    std::cin >> k;

    i64 tot = 2LL * k - 1;
    tot *= tot;

    i64 rem = (k - 1) / 2;

    i64 del = (rem + 1) * rem * 2;
    std::cout << tot - del;

    return 0;
}

