/**
 *    author:  Yuyuan
 *    created: 2026-04-18 20:17:03
 **/
#include <bits/stdc++.h>

void solve() {
    int a, b;
    std::cin >> a >> b;
    if (b % a == 0) {
        std::cout << b / a * b << '\n';
    } else {
        std::cout << std::lcm(a, b) << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
