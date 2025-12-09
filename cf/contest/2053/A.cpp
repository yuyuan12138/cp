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
    vector<int> a(n);
    for(auto& x: a){
        cin >> x;
    }
    for(int i = 0; i < n - 1; i++){
        if(min(a[i], a[i + 1]) * 2 > max(a[i], a[i + 1])){
            cout << "YES\n";
            return ;
        }
    }
    cout << "NO\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}