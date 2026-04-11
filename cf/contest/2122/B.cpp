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
    int n; 
    cin >> n;

    ll ans = 0LL;
    for(int i = 1; i <= n; i++){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ans += max(a - c, 0LL) + max(b - d, 0LL);
        if(b > d){
            ans += min(a, c);
        }
    }
    cout << ans << "\n";
    
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}