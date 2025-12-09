#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 a, b;
    std::cin >> a >> b;
    std::cout << a * b - a - b;
    return 0;
}