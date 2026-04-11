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

#define ll long long

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n + 2, vector<int>(m + 2));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> grid[i][j];
        }
    }
    vector<bool> is_connect(m * n + 2, false);
    vector<bool> vis_color(m * n + 2, false);
    int num_of_color = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(grid[i][j] == grid[i - 1][j] || grid[i][j] == grid[i + 1][j]
            || grid[i][j] == grid[i][j - 1] || grid[i][j] == grid[i][j + 1]){
                is_connect[ grid[i][j] ] = true;
            }
            if(!vis_color[ grid[i][j] ]){
                vis_color[ grid[i][j] ] = true;
                num_of_color++;
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <= m * n; i++){
        if(is_connect[i]) cnt++;
    }
    if(cnt == 0){
        cout << num_of_color - 1 << "\n";
    }else{
        cout << num_of_color + cnt - 2 << "\n";
    }
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}