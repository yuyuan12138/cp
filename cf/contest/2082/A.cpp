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
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
        int tmp = 0;
        for(int j = 0; j < m; j++){
            tmp ^= (int)(grid[i][j] - '0');
        }
        cnt1 += tmp;
    }
    for(int i = 0; i < m; i++){
        int tmp = 0;
        for(int j = 0; j < n; j++){
            tmp ^= (int)(grid[j][i] - '0');
        }
        cnt2 += tmp;
    }
    // if(n == 1){
    //     cout << cnt2 << "\n";
    //     return ;
    // }
    // if(m == 1){
    //     cout << cnt1 << "\n";
    //     return ;
    // }
    cout << max(cnt1, cnt2) << "\n";

    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}