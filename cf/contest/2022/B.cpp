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
    ll n, x; cin >> n >> x;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    if(x >= n){
        cout << *max_element(all(a)) << "\n";
        return ;
    }
    int cnt = 0;
    
    ll sum = accumulate(all(a), 0LL);
    cout << max((sum + x - 1) / x, *max_element(all(a))) << "\n";

    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}