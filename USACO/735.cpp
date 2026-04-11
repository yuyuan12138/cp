#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::freopen("lostcow.in", "r", stdin);
    std::freopen("lostcow.out", "w", stdout);
    int x, y;
    std::cin >> x >> y;
    int ans = 0;
    int pos = x;
    for (int i = 1, sign = 1; i <= 20; i++) {
        int next = (1 << (i - 1)) * (sign == 1 ? 1 : -1);
        sign ^= 1;
        if ((x <= y && x + next >= y) || (x >= y && x + next <= y)) {
            ans += std::abs(pos - y);
            break;
        }
        ans += std::abs(next + x - pos);
        pos = next + x;
    }
    std::cout << ans;
    return 0;
}