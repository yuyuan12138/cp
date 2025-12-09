/**
 *      author:  yuyuan567
 *      created: 2025-08-11 23:54:35
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "../../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

#define int long long

using ll = long long;
using ull = unsigned long long;

constexpr int MOD = 1e9 + 7;


void solve(){
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
    }

    std::sort(all(a));

    // if (n == 1 || k == 1) {
    //     std::cout << a[0] << "\n";
    //     return ;
    // }
    
    std::vector<int> dp(31, 0);
    dp[0] = 1;
    for (int i = 1; i < 31; i++) {
        dp[i] = i + 1;
        for (int j = 0; j < i; j++) {
            dp[i] = dp[i] * dp[j] % MOD;
        }
    }
    auto self = [&](this auto&& self, int v, int k) -> int {
        if (k == 0) return 1;
        int ans = (v + 1) % MOD;
        v = std::min(v - 1, 30LL);
        k -= 1;
        for (int j = 0; j <= v; j++) {
            if (k >= 1 << j) {
                ans *= dp[j];
                ans %= MOD;
                k -= 1 << j;
            } else {
                ans *= self(j, k);
                ans %= MOD;
                break ;
            }
        }
        return ans;
    };
    
    int ans = 1;

    for (auto x: a) {
        if (x <= 30 && k >= 1 << x) {
            k -= 1 << x;
            ans *= dp[x];
            ans %= MOD;
        } else {
            ans *= self(x, k);
            ans %= MOD;
            break;
        }
    }

    std::cout << ans % MOD << "\n";
    

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