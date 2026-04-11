/**
 *      author:  yuyuan567
 *      created: 2025-07-27 23:22:35
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
    vector<int> b(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }

    if(b[1] == 0){
        for(int i = 2; i <= n; i++){
            if(b[i]){
                cout << "NO\n";
                return ;
            }
        }
    }else{
        int tmp = b[1];
        for(int i = 2; i <= n; i++){
            if(b[i] >= 2 * tmp){
                cout << "NO\n";
                return ;
            }
            tmp = min(tmp, b[i]);
        }
    }
    cout << "YES\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}