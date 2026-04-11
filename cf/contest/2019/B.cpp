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
    ll n, q; cin >> n >> q;
    vector<int> x(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> x[i];
    }
    map<ll, ll> mp;
    for(ll i = 1; i <= n; i++){
        mp[i * (n - i + 1LL) - 1LL] += 1LL;
    }
    for(int i = 2; i <= n; i++){
        int cnt = x[i] - x[i - 1] - 1;
        ll num_intervals = (i - 1) * (n - i + 1);
        if(mp.find(num_intervals) == mp.end()){
            mp[num_intervals] = 0;
        }
        mp[num_intervals] += cnt;
    }

    while(q--){
        ll k; cin >> k;
        if(mp.find(k) == mp.end()){
            cout << "0 ";
        }else{
            cout << mp[k] << " ";
        }
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