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
    int n, m;
    cin >> n >> m;
    int ans = 4 * m;
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        if(i == 1) continue;
        ans += 2 * (x + y);
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