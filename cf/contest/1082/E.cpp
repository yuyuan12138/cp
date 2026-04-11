/**
 *      author:  yuyuan567
 *      created: 2025-07-26 16:57:21
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
    int n, c; cin >> n >> c;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> dp(5e5 + 5);
    int mx = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == c){
            cnt++;
        }else{
            dp[a[i]] = max(dp[a[i]], cnt) + 1;
        }
        mx = max(mx, dp[a[i]] - cnt);
    }
    cout << mx + cnt << "\n";
    return ;
}

int main() {
    speedup();
    solve();
    return 0;
}