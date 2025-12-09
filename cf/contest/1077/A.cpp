/**
 * @author: yuyuan567
 *
 * @date: 2025-07-25 10:23:18
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
    int n; cin >> n;
    vector<ll> b(2 * n + 1);
    for(int i = 1; i <= 2 * n; i++){
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    ll tot = 0;
    vector<ll> a(2 * n + 2);
    for(int i = 1; i <= 2 * n - 3; i += 2){
        tot += b[i + 1] - b[i];
        debug(tot);
        a[i] = b[i + 1];
        a[i + 1] = b[i];
    }
    
    tot = tot + b[2 * n - 1] + b[2 * n];

    debug(tot);
    a[2 * n - 1] = b[2 * n - 1];
    a[2 * n + 1] = b[2 * n];
    a[2 * n] = tot;
    for(int i = 1; i <= 2 * n + 1; i++){
        cout << a[i] << " "; 
    }
    cout << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}