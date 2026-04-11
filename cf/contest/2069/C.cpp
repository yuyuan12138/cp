/**
 *      author:  yuyuan567
 *      created: 2025-07-25 23:58:20
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
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    vector<int> dp(4, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        if(a[i] == 2){
            dp[2] = (dp[2] * 2) % mod;
        }
        dp[a[i]] = (dp[a[i]] + dp[a[i] - 1]) % mod;
    }
    int ans = 0;
    
    cout << dp[3] << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}