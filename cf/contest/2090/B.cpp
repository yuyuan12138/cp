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
    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(grid[i][j] == '0') continue;
            bool flag1 = true, flag2 = true;
            for(int row = i - 1; row >= 0; row--){
                if(grid[row][j] != '1'){
                    flag1 = false;
                }
            }
            for(int col = j - 1; col >= 0; col--){
                if(grid[i][col] != '1'){
                    flag2 = false;
                }
            }
            if((!flag1) && (!flag2)){
                cout << "NO\n";
                return ;
            }
        }
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