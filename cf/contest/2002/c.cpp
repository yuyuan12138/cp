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
    vector<ll> x(n + 1);
    vector<ll> y(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }
    ll xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    auto check = [&](int idx) -> bool {
        if((xt - xs) * (xt - xs) + (yt - ys) * (yt - ys) < (x[idx] - xt) * (x[idx] - xt) + (y[idx] - yt) * (y[idx] - yt)){
            return true;
        }
        return false;
    };
    for(int i = 1; i <= n; i++){
        if(!check(i)){
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}