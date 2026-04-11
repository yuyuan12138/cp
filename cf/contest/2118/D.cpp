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
    ll n, k; cin >> n >> k;
    vector<ll> traffic_pos(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> traffic_pos[i];
    }
    vector<ll> delay(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> delay[i];
    }

    
    int q; cin >> q;

    // O(q * n)
    while(q--){
        ll pos; cin >> pos;
        ll idx = 1;
        while(traffic_pos[idx] < pos && idx != n + 1){
            idx++;
        }
        ll t = 0;
        int dir = 1;
        set<vector<ll>> vis;
        
        while(idx != n + 1 && idx != 0){
            t = (t + abs(traffic_pos[idx] - pos)) % k;
            if(t % k == delay[idx]){
                dir *= -1;
            }
            if(vis.count({idx, dir, t})){
                break;
            }
            vis.insert({idx, dir, t});
            pos = traffic_pos[idx];
            idx += dir;
        }
        if(idx == n + 1 || idx == 0){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    
    
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}