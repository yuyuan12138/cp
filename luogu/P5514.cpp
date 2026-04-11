#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 0, x; i < n; i++) {
        std::cin >> x;
        if (i == 0) {
            ans = x;
        } else {
            ans ^= x;
        }
    }
    std::cout << ans;
    return 0;
}
