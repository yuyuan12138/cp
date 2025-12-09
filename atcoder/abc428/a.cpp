#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int s, a, b, x;
    std::cin >> s >> a >> b >> x;
    int cnt = x / (a + b);
    int ans = cnt * s * a;
    x -= cnt * (a + b);
    if (x <= a) {
        std::cout << ans + x * s << '\n';
    } else {
        std::cout << ans + a * s << '\n';
    }
    return 0;
}
