/**
 * @author: yuyuan567
 *
 * @date: 2025-07-24 23:55:41
 */

#undef _GLIBCXX_DEBUG

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
    ll x, n, m; cin >> x >> n >> m;

    if(n == m && n == 0){
        cout << x << " " << x << "\n";
    }else{
        ll store = x;
        ll nn = n;
        ll mm = m;
        while(x > 1 && m > 0){
            m--;
            // x++;
            x = ((x + 1) >> 1);
        }

        while(x > 0 && n > 0){
            n--;
            // x >>= 1;
            x = (x >> 1);
        }
        
        cout << x << " ";
        x = store;
        n = nn;
        m = mm;
        while(x > 0 && n > 0){
            n--;
            x = (x >> 1);
        }
        while(x > 1 && m > 0){
            m--;
            x = ((x + 1) >> 1);
        }
        cout << x << "\n";
    }



    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}