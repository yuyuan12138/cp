/**
 *      author:  yuyuan567
 *      created: 2025-07-25 23:30:09
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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++){
        if(s[i - 1] == 'B') v[i] = 1;
        else v[i] = 0;
    }
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    int l = 0, r = 1e9;
    while(l <= r){
        int mid = (l + r) >> 1;
        if([&](){
            int last = 0;
            int cnt = 0;
            for(int i = 1; i <= n; i++){
                if(a[i] > mid && last != v[i]){
                    last = v[i];
                    if(v[i] == 1){
                        cnt++;
                    }
                }
            }
            if(cnt <= m){
                return true;
            }else{
                return false;
            }
        }()){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    cout << l << "\n";

    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}