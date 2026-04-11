#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string> 
#include <string.h>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <bitset>
#include <forward_list>
#include <deque>
#include <set>
#include <tuple>
#include <utility>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <chrono>
#include <random>
#include <complex>
#include <functional>
#include <cassert>
#include <climits>
#include <limits>
#include <tuple>
#include <cstdint>
#include <array>

using namespace std;
using data = int;

#define ll long long

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    int n; cin >> n;
    vector<ll> vertex(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> vertex[i];
    }
    vector<vector<int>> adjacent_matrix(n + 1);
    for(int i = 1; i <= n - 1; i++){
        int u, v;
        cin >> u >> v;
        adjacent_matrix[u].push_back(v);
        adjacent_matrix[v].push_back(u);
    }
    
    vector<ll> ans(n + 1);
    auto dfs = [&](auto&& dfs, int idx, vector<bool>& vis, ll min_num, ll max_num){
        if(vis[idx]) return ;
        vis[idx] = true;
        
        ans[idx] = max(vertex[idx], vertex[idx] - min_num);
        
        for(int i = 0; i < adjacent_matrix[idx].size(); i++){
            dfs(dfs, adjacent_matrix[idx][i], vis, min(vertex[idx], vertex[idx] - max_num), ans[idx]);  
        }

    };
    vector<bool> vis(n + 1, false);
    dfs(dfs, 1, vis, 0, 0);
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
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