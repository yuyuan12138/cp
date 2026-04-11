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
    vector<int> p(n + 1);
    vector<int> s(n + 1);
    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= n; i++) cin >> s[i];
    if(p[n] != s[1]){
        cout << "NO\n";
        return ;
    }
    for(int i = 1; i <= n - 1; i++){
        if(p[n] != gcd(p[i], s[i + 1])){
            cout << "NO\n";
            return ;
        }
    }
    for(int i = n; i >= 2; i--){
        if(p[n] != gcd(s[i], p[i - 1])){
            cout << "NO\n";
            return ;
        }
    }
    for(int i = 1; i <= n - 1; i++){
        if(s[i + 1] % s[i] != 0){
            cout << "NO\n";
            return ;
        }
    }
    for(int i = 2; i <= n; i++){
        if(p[i - 1] % p[i] != 0){
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
    vector<int> a(n + 1);
    


    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}