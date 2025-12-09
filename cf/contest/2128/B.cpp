/**
 *      author:  yuyuan567
 *      created: 2025-07-27 23:03:12
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
    for(int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = n;
    int state = 0;
    string res = "";
    while(l < r){
        if(state == 1 && a[l] < a[r]){
            state = 0;
            res += "R"; res += "L";
        }else 
        if(state == 1 && a[l] > a[r]){
            state = 0;
            res += "L"; res += "R";
        }else 
        if(state == 0 && a[l] < a[r]){
            state = 1;
            res += "L"; res += "R";
        }else 

        if(state == 0 && a[l] > a[r]){
            state = 1;
            res += "R"; res += "L";
        }

        l++; r--;
    }
    if(l == r){
        res += "R";

    }
    cout << res << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}