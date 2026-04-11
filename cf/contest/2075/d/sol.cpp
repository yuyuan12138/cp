/**
 *      author:  yuyuan567
 *      created: 2025-08-19 10:30:13
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    const int B = 61;
    const ll INF = 2e18;
    std::vector<std::vector<ll>> f(B, std::vector<ll> (B, INF));
    f[0][0] = 0;
    for (int x = 0; x < B; x++) {
        for (int i = B - 1; i >= 0; i--) {
            for (int j = B - 1; j >= 0; j--) {
                if (f[i][j] == INF) continue;
                if (x + i < B) {
                    f[i + x][j] = std::min(
                            f[i + x][j], 
                            f[i][j] + (1LL << x)
                            );
                } 
                if (x + j < B) {
                    f[i][x + j] = std::min(f[i][j + x], f[i][j] + (1LL << x));
                }
            }
        }
    }    
    int tt;
    std::cin >> tt;
    while (tt--) {
        ll x, y;
        std::cin >> x >> y;
        ll ans = INF;
        for (int i = 0; i < B; i++) {
            for (int j = 0; j < B; j++) {
                if ((x >> i) == (y >> j)) {
                    ans = std::min(ans, f[i][j]);
                }
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}
