/**
 *      author:  yuyuan567
 *      created: 2025-07-25 16:29:12
 */
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    const int mod = 998244353;
    int n; cin >> n;
    vector<int> par(n + 1);
    vector<vector<int>> by_h(n + 2);
    vector<int> depth(n + 1);
    depth[1] = 1;
    for(int i = 2; i <= n; i++){
        cin >> par[i];
        depth[i] = depth[par[i]] + 1;
    }
    
    for(int i = 1; i <= n; i++){
        by_h[depth[i]].emplace_back(i);
    }
    
    vector<int> dp(n + 1);
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        if(by_h[i].empty()) break;
        int s = 0;
        for(int j: by_h[i - 1]){
            s = (s + dp[j]) % mod;
        }
        for(int j: by_h[i]){
            dp[j] = s;
            if(par[j] != 1) {
                dp[j] = (dp[j] - dp[par[j]] + mod) % mod;
            }
        }
    }
    debug(dp);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = (ans + dp[i]) % mod;
    }
    cout << ans << "\n";
    
    
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}