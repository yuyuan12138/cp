/**
 *      author:  yuyuan567
 *      created: 2025-07-27 16:36:14
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
    for (int l = 0; l <= 9; l++) {
        string s = to_string(n - l);
        int md = 0;
        for (auto& c: s) {
            if (c <= '7'){
                md = max(md, c - '0');
            }
        }
        if(l >= 7 - md){
            cout << l << "\n";
            return ;
        }
    }
    
    
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}