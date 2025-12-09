/**
 *      author:  yuyuan567
 *      created: 2025-08-13 00:03:03
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

#define int long long

void solve(){
    int n, h, k;
    std::cin >> n >> h >> k;
    ll cur = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        if (cur + x > h) {
            int l = 1, r = 1e6 + 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (cur - mid * k + x <= h) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            // r
            // debug(r);
            
            ans += l;
            cur -= k * l;
            cur = std::max(0LL, cur);
        } 
        cur += x;
        // debug(cur);
    }
    // debug(ans);
    ans += (cur + k - 1) / k;
    // debug(ans);
    std::cout << ans;
    
    return ;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    solve();
    return 0;
}