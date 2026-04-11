/**
 *    author:  yuyuan
 *    created: 2025-12-26 11:23:11
 **/
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
constexpr int64_t inf = 1e18;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<array<int64_t, 2>>> dp(n + 1, vector<array<int64_t, 2>> (n + 1, {-inf, -inf})); 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        dp[i][i][0] = a[i];
        dp[i][i][1] = 0;
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            if (len % 2 == 1) {
                dp[l][r][0] = min(dp[l + 1][r][0] + a[l], dp[l][r - 1][0] + a[r]);
                dp[l][r][1] = min(dp[l + 1][r][1], dp[l][r - 1][1]);
            } else {
                dp[l][r][0] = min(dp[l + 1][r][0], dp[l][r - 1][0]);
                dp[l][r][1] = min(dp[l + 1][r][1] + a[l], dp[l][r - 1][1] + a[r]);
            }
        }
    }
    cout << dp[0][n - 1][0];
 
 
    return 0;
}
 

