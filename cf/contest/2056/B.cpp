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
    int n; cin >> n;
    vector<string> sv(n);
    for(auto& x: sv){
        cin >> x;
    }
    vector<vector<int>> grids(n + 1, vector<int>(n + 1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            grids[i + 1][j + 1] = sv[i][j] - '0';
        }
    }
    vector<int> res(n);
    iota(all(res), 1);

    sort(res.begin(), res.end(), 
        [&](int x, int y){
            if(grids[x][y] == 1){
                return x < y;
            }else{
                return x > y;
            }
        }
    );

    
    for(auto& x: res){
        cout << x << " ";
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