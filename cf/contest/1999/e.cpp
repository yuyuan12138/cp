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

ll a[int(2 * 1e5) + 2];

void init(){
    int tmp = 1;
    int j = 0;
    for(int i = 1; i <= 2 * 1e5 + 1; i++){
        while(tmp <= i){
            tmp = tmp * 3;
            j++;
        }
        a[i] = a[i - 1] + j;
    }

}

void solve(){
    int l, r; cin >> l >> r;
    
    cout << a[r] - a[l - 1] + a[l] - a[l - 1] << "\n";
    return ;
}

int main() {
    speedup();
    init();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}