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
    vector<pair<int, int>> dir = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };

    int idx = 0;
    vector<vector<int>> ans(n + 1, vector<int>(n + 1));
    int pos_x = 1, pos_y = 1;
    int num = n * n - 1;
    while(num >= 1){
        ans[pos_x][pos_y] = num;
        num--;
        if(idx == 0 && (pos_y == n || ans[pos_x][pos_y + 1] != 0)){
            idx = 1;
        }else if(idx == 1 && (pos_x == n || ans[pos_x + 1][pos_y] != 0)){
            idx = 2;
        }else if(idx == 2 && (pos_y == 1 || ans[pos_x][pos_y - 1] != 0)){
            idx = 3;
        }else if(idx == 3 && (pos_x == 1 || ans[pos_x - 1][pos_y] != 0)){
            idx = 0;
        }

        auto [x, y] = dir[idx];
        pos_x += x, pos_y += y;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}