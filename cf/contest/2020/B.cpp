#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using pii = pair<int, int>;

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    ll k; cin >> k;
    ll l = 1, r = LLONG_MAX;
    while(l <= r){
        ll mid = l + (r - l) / 2;
        ll n = mid - int(sqrtl(mid));
        if(n >= k){
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