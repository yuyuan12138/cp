#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int x, y, z, n, m;
    std::cin >> x >> y >> z >> n >> m;
    int ans = 0;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; i + j <= m; j++) {
            for (int k = 0; i + j + k <= m; k += z) {
                if (i * x + j * y + k / z == n && i + j + k == m) {
                    ans++;
                }
            }
        }
    }
    
    std::cout << ans;
    return 0;
}