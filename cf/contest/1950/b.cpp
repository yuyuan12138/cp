/**
 *      author:  yuyuan567
 *      created: 2025-08-07 16:02:46
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "../../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;

void solve(){
    int n;
    std::cin >> n;
    std::vector<std::vector<char>> grids(2 * n, std::vector<char> (2 * n));
    bool ok = false;
    for (int i = 0; i < 2 * n; i += 2) {
        ok ^= 1;
        bool ok2 = false;
        for (int j = 0; j < 2 * n; j += 2) {
            ok2 ^= 1;
            for (int k = i; k <= i + 1; k++) {
                for (int y = j; y <= j + 1; y++) {
                    if (ok ^ ok2) {
                        grids[k][y] = '.';
                    } else {
                        grids[k][y] = '#';
                    }
                }
                
            }
        }
    }

    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            std::cout << grids[i][j] << "";
        }
        std::cout << "\n";
    }

    return ;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1; std::cin >> t;
    while(t--) solve();
    return 0;
}