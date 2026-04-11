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
    ll a, b, k;
    cin >> a >> b >> k;
    if(a == 0 || b == 0){
        cout << 1 << "\n";
        return ;
    }
    if(a - k <= 0 && b - k <= 0){
        cout << 1 << "\n";
        return ;
    }
    ll tmp = gcd(a, b);
    if(k >= a / tmp && k >= b / tmp){
        cout << 1 << "\n";
        return ;
    }
    cout << 2 << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}