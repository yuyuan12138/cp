#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    for (int i = 0, x; i < n; i++) {
        std::cin >> x;
        int cnt = 0;
        for (int j = 1; j * j <= x; j++) {
            if (x % j == 0) {
                cnt += 2;
            }
            if (j * j == x) {
                cnt--;
            }
        }
        std::cout << cnt << '\n';
    }
    return 0;
}
