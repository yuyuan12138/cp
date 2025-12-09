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
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if(((b & 1) == 1) && a == b - 1){
        cout << min(x, y) << "\n";
        return ;
    }
    if(((b & 1) == 0) && (a == b + 1)){
        cout << y << "\n";
        return ;
    }
    // cout << "----\n";
    if( a == b){
        cout << 0 << "\n";
        return ;
    }
    int cost = 0;
    if( a > b ){
        cout << -1 << "\n";
        return ;
    }
    while(a < b){
        if((a & 1) == 0){
            cost += min(x, y);
        }else{
            cost += x;
        }
        a += 1;
    }
    cout << cost << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}