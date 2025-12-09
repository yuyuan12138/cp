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
    vector<vector<int>> a(n, vector<int> (2));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            cin >> a[i][j];
        }
    }
    sort(all(a), [](vector<int>& a, vector<int>& b){
        if(max(a[0], a[1]) < min(b[0], b[1])){
            return true;
        }
        if(min(a[0], a[1]) > max(b[0], b[1])){
            return false;
        }
        return a[0] + a[1] < b[0] + b[1];
    });
    for(int i = 0; i < n; i++){
        cout << a[i][0] << " " << a[i][1] << " ";
    }
    cout << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}