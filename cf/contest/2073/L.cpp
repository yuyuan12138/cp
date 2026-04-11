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
    int r, c, n, p; cin >> r >> c >> n >> p;
    vector<vector<int>> grids(r + 1, vector<int>(c + 1));
    vector<pair<int, int>> travalers(p);
    // int x, y;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> grids[i][j];
            if(grids[i][j] <= p && grids[i][j] != 0){
                travalers[grids[i][j] - 1] = make_pair(i, j);
            }
        }
    }
    set<int> seen;
    
    int num_travalers = travalers.size();
    for(int i = 0; i < num_travalers; i++){
        int dis = num_travalers - i - 1;
        int x = travalers[i].first;
        int y = travalers[i].second;
        // cout << dis << "\n";
        if(x != 1 && grids[x - 1][y] != 0){
            if(dis + grids[x - 1][y] <= n){
                seen.insert(dis + grids[x - 1][y]);
            }
        }
        if(x != r && grids[x + 1][y] != 0){
            if(dis + grids[x + 1][y] <= n){
                seen.insert(dis + grids[x + 1][y]);
            }
        }
        if(y != 1 && grids[x][y - 1] != 0){
            if(dis + grids[x][y - 1] <= n) {
                seen.insert(dis + grids[x][y - 1]);
            }
        }
        if(y != c && grids[x][y + 1] != 0){
            if(dis + grids[x][y + 1] <= n) {
                seen.insert(dis + grids[x][y + 1]);
            }
        }
        // for(auto it: seen){
        //     cout << it << " ";
        // }
        // cout << "\n";
    }
    
    cout << seen.size() << "/" << n - 1;
    return ;
}

int main() {
    speedup();
    solve();
    return 0;
}