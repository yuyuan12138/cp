/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-06-17 23:52:40
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-06-17 23:52:40
 * @FilePath: \Codeforces Round 1032 (Div. 3)\E.cpp
 * @Description: 
 * @
 * @Copyright (c) ${Date} by ${115848824+yuyuan12138@users.noreply.github.com}, All Rights Reserved. 
 */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10;
const int INF = 1e9;

void solve() {
    
    string l_str, r_str;
    cin >> l_str >> r_str;
    int n = l_str.size();
    vector<int> L(n), R(n);
    for (int i = 0; i < n; ++i) {
        L[i] = l_str[i] - '0';
        R[i] = r_str[i] - '0';
    }

    int dp[MAXN][2][2];
    for (int i = 0; i <= n; ++i)
        for (int tl = 0; tl < 2; ++tl)
            for (int tr = 0; tr < 2; ++tr)
                dp[i][tl][tr] = INF;

    dp[0][1][1] = 0;

    for (int i = 0; i < n; ++i) {
        for (int tl = 0; tl < 2; ++tl) {
            for (int tr = 0; tr < 2; ++tr) {
                if (dp[i][tl][tr] == INF) continue;
                int low = tl ? L[i] : 0;
                int high = tr ? R[i] : 9;
                for (int d = low; d <= high; ++d) {
                    int ntl = tl && (d == L[i]);
                    int ntr = tr && (d == R[i]);
                    int contrib = (d == L[i]) + (d == R[i]);
                    dp[i + 1][ntl][ntr] = min(dp[i + 1][ntl][ntr], dp[i][tl][tr] + contrib);
                }
            }
        }
    }

    int ans = INF;
    for (int tl = 0; tl < 2; ++tl)
        for (int tr = 0; tr < 2; ++tr)
            ans = min(ans, dp[n][tl][tr]);
    cout << ans << "\n";
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}