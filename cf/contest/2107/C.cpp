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

/**
 *  Record how to find maximum subarray (Two pointers solution)
 *  We can find the upper_bound and lower_bound of the solution. 
 *  
 *  Observation:
 */

void solve(){
    int n; ll k; cin >> n >> k;
    string s; cin >> s;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int pos = -1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0'){
            pos = i + 1;
            a[i + 1] = -1e13;
        }
    }
    

    ll mx = 0;
    ll cur = 0;
    for(int i = 1; i <= n; i++){
        cur = max(cur + a[i], a[i]);
        mx = max(cur, mx);
    }
    if(mx > k || (mx != k && pos == -1)){
        cout << "NO\n";
        return ;
    }

    if(pos != -1){
        mx = 0, cur = 0;
        ll l = 0, r = 0;
        for(int i = pos + 1; i <= n; i++){
            cur += a[i];
            mx = max(cur, mx);
        }
        r = mx;
        mx = 0, cur = 0;
        for(int i = pos - 1; i >= 1; i--){
            cur += a[i];
            mx = max(cur, mx);
        }
        l = mx;
        a[pos] = k - l - r;
        
    }
    
    cout << "YES\n";
    for(int i = 1; i <= n; i++){
        cout << a[i] << " \n"[i == n]; 
    }

}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}