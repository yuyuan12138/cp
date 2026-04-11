#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    int l = 0, r = m;
    while(l <= r){
        int mid = (r - l) / 2 + l;
        if((m / (mid + 1) * mid + m % (mid + 1)) * n >= k){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    cout << l << endl;
}

signed main(){
    int t;
    cin >> t;
    while (t--)
    {
        /* code */
        solve();
    }
    
}