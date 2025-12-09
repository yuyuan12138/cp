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
    const int mod = 1e9 + 7;
    vector<int> pw(n + 1);
    pw[0] = 1;
    for(int i = 1; i <= n; i++){
        pw[i] = (pw[i - 1] * 2) % mod;
    }

    vector<vector<int>> g(n + 1);
    for(int i = 1; i <= n - 1; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> heights(n + 1);

    [&](this auto&& self, int x, int pa) -> void {
        heights[x] = heights[pa] + 1;
        for(int i = 0; i < g[x].size(); i++){
            if(g[x][i] == pa) continue;
            self(g[x][i], x);
        }
    } (1, 0);
    int cnt = 0;
    int p = 1;
    vector<int> leaf;
    for(int i = 2; i <= n; i++){
        if(g[i].size() == 1){
            cnt++;
            leaf.push_back(i);
        }
        if(g[i].size() == 3){
            p = i;
        }
    }
    
    if(cnt >= 3){
        cout << "0\n";
    }else if(cnt == 1){
        cout << pw[n] << "\n";
    }else{
        int diff = abs(heights[leaf[0]] - heights[leaf[1]]);
        int x = diff + heights[p];
        if(diff){
            cout << (pw[x] + pw[x - 1]) % mod << "\n";
        }else{
            cout << 2 * pw[x] % mod << "\n";
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