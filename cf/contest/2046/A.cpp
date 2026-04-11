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
#define all(x) (x).begin(), (x).end()

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    int num_of_columns; 
    cin >> num_of_columns;
    int ans = 0;
    vector<vector<int>> grids(3, vector<int> (num_of_columns + 1));
    for(int i = 1; i <= 2; i++){
        for(int j = 1; j <= num_of_columns; j ++){
            cin >> grids[i][j];
        }
    }
    int mx = INT32_MIN;
    for(int j = 1; j <= num_of_columns; j++){
        ans += max(grids[1][j], grids[2][j]);
        if(grids[1][j] > grids[2][j]){
            mx = max(mx, grids[2][j]);
        }else{
            mx = max(mx, grids[1][j]);
        }
    }
    cout << ans + mx << "\n";

    // vector<int> idx(num_of_columns);
    // iota(all(idx), 1);
    // vector<int> diff(num_of_columns + 1);
    // for(int i = 1; i <= num_of_columns; i++){
    //     diff[i] = grids[1][i] - grids[2][i];
    // }
    // sort(all(idx), [&](int a, int b){
    //     return diff[a] > diff[b];
    // });
    // int ans = 0;
    // // bool flag = false;
    // int st = -0x3f3f3f3f;
    // for(int i = 0; i < num_of_columns; i++){
    //     if(diff[idx[i]] >= 0){
    //         ans += grids[1][idx[i]];
    //         st = max(st, grids[2][idx[i]]);
    //     }else{
    //         st = max(st, grids[1][idx[i]]);
    //         ans += grids[2][idx[i]];
    //     }
        
    // }
    // cout << ans + st << "\n"; 
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}