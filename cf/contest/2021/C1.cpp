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
    int n, m, q; cin >> n >> m >> q;
    vector<int> members(n + 1);
    vector<int> members_pos(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> members[i];
        members_pos[members[i]] = i;
    }
 
    vector<int> slices(m + 1);
    for(int i = 1; i <= m; i++){
        cin >> slices[i];
    }
    vector<pair<int, int>> queries(q + 1);
    for(int i = 1; i <= q; i++){
        cin >> queries[i].first >> queries[i].second;
    }
 
    auto check = [&]() -> bool {
        int slow = 0; 
        for(int fast = 1; fast <= m; fast++){
            if(members_pos[slices[fast]] > slow + 1){
                return false;
            }
            slow = max(slow, members_pos[slices[fast]]);
        }
        return true;
    };    
    if(check()){
        cout << "YA\n";
    }else{
        cout << "TIDAK\n";
    }
 
    for(int i = 1; i <= q; i++){
        int x = queries[i].first, y = queries[i].second;
        slices[x] = y;
        if(check()){
            cout << "YA\n";
        }else{
            cout << "TIDAK\n";
        }
    }
    
    return ;
}
 
int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}