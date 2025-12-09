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
    int n, k; cin >> n >> k;
    vector<vector<int>> casinos(n + 1, vector<int> (4));
    for(int i = 1; i <= n; i++){
        cin >> casinos[i][1] >> casinos[i][2] >> casinos[i][3];
    }
    sort(all(casinos), [](vector<int>& a, vector<int>& b){
        if(a[3] == b[3]){
            if(a[2] < b[2]){
                return true;
            }
        }else{
            if(a[3] < b[3]){
                return true;
            }
        }
        return false;
    });

    for(int i = 1; i <= n; i++){
        if(k >= casinos[i][1] && k <= casinos[i][2]){
            k = max(k, casinos[i][3]);
        }
    }           
    cout << k << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}