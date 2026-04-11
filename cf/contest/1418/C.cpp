/**
 *      author:  yuyuan567
 *      created: 2025-07-26 15:33:55
 */
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../../algo/debug.h"
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
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<vector<int>> dp(n + 1, vector<int> (3, 0x3f3f3f3f));
    dp[1][2] = a[1];
    dp[0][1] = 0;
    // dp[i][j] j's end round. 1: me. 2: friend
    for(int i = 2; i <= n; i++){
        dp[i][1] = min(dp[i - 1][2], dp[i - 2][2]);
        dp[i][2] = min(dp[i - 1][1] + a[i], dp[i - 2][1] + a[i] + a[i - 1]);
    }  
    cout << min(dp[n][1], dp[n][2]) << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}