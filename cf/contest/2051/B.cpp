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
    int a, b, c, n;
    cin >> n >> a >> b >> c;
    int tot = a + b + c;
    int cnt = n / tot;
    int last = n - n / tot * tot;
    if(last == 0){
        cout << cnt * 3 << "\n";
        return ;
    }
    if(last <= a){
        cout << cnt * 3 + 1 << "\n";
    }else if(last <= a + b){
        cout << cnt * 3 + 2 << "\n";
    }else{
        cout << cnt * 3 + 3 << "\n";
    }
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}