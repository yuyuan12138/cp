/**
 *    author:  Yuyuan
 *    created: 2026-04-18 15:13:15
 **/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 a, b;
    std::cin >> a >> b;
    int cnt = 0;
    if (a >= b) {
        std::cout << a - b;
    } else {
        while (a < b) {
            a *= 2;
            cnt++;
        }
        std::cout << std::min(b - a / 2 - 1, a - b) + cnt;
    }
    return 0;
}
