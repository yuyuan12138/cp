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
    vector<int> heights(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> heights[i];
    }
    int num = heights[k];
    sort(all(heights));
    int idx = 0;
    for(int i = 1; i <= n; i++){
        if(heights[i] == num){
            idx = i;
        }
    }
    
    int water = 0;
    for(int i = idx; i <= n - 1; i++){
        // cout << i << " ";
        if(heights[i] - water < heights[i + 1] - heights[i]){
            cout << "NO\n";
            return ;
        }
        water += heights[i + 1] - heights[i];
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