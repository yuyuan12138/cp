/**
 *      author:  yuyuan567
 *      created: 2025-08-06 18:42:53
 */
#include <bits/stdc++.h>


#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;

void solve(){
    int n;
    std::cin >> n;

    std::vector<int> freq(5003);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        freq[x]++;
        mx = std::max(mx, x);
    }
    
    int ans = 0;
    for (int s = 2; s <= 2 * mx; s++) {
        int p = 0;
        for (int x = 1; x <= s / 2; x++) {
            int y = s - x;
            if (y > mx) {
                continue;
            }
            if (x == y) {
                p += freq[x] / 2;
            } else {
                p += std::min(freq[x], freq[y]);
            }
        }
        ans = std::max(ans, p);
    }
    std::cout << ans * 2;

    return ;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    solve();
    return 0;
}