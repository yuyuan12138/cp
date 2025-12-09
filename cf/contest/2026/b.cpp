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
    int n; cin >> n;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(n % 2 == 0){
        ll dis = 0;
        for(int i = 2; i <= n; i+=2){
            dis = max(dis, a[i] - a[i - 1]);
        }
        cout << dis << "\n";
    }else{
        if(n == 1){
            cout << 1 << "\n";
            return ;
        }
        // vector<ll> diss;
        // for(int i = 2; i <= n; i++){
        //     diss.push_back(a[i] - a[i - 1]);
        // }
        // sort(all(diss));
        // cout << diss[diss.size() - 2] << "\n";
        ll ans = LLONG_MAX;
        for(int i = 1; i <= n; i++){
            ll dis = 0;
            for(int j = 2; j <= n; j += 2){
                if(j - 1 == i){
                    j += 1;
                }
                dis = max(dis, a[j] - a[j - 1]);
            }
            ans = min(ans, dis);
        }
        cout << ans << "\n";
    }
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}