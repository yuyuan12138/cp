/**
 *      author:  yuyuan567
 *      created: 2025-08-10 15:00:34
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
    std::string s;
    std::cin >> s;
    
    ll ans = 0;
    std::vector<ll> cnt = {1, 0};
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (s[i] == '0');
        ans += cnt[sum & 1];
        cnt[sum & 1] ++;
    }
    std::cout << ans << "\n";

    return ;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    solve();
    return 0;
}