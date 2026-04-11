#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using pii = pair<int, int>;

/**
 * 
 * 
 */

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> teachers(m + 1);
    for(int i = 1; i <= m; i++){
        cin >> teachers[i];
    }
    sort(all(teachers));
    for(int i = 1; i <= q; i++){
        int a; cin >> a;
        int l = 1, r = m;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(teachers[mid] >= a){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        if(l == 1){
            cout << teachers[1] - 1 << "\n";
            continue;
        }
        if(r == m){
            cout << n - teachers[m] << "\n";
            continue;
        }
        cout << (teachers[l] - teachers[l - 1]) / 2 << "\n";
    }
    
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}