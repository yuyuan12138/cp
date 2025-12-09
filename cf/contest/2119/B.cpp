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
#define int long long

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}


void solve(){
    int n; cin >> n;
    int px, py, zx, zy;
    cin >> px >> py >> zx >> zy;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(n == 0 && px == zx && py == zy){
        cout << "Yes\n";
        return ;
    }
    ll min_dis = 0;
    ll max_dis = accumulate(a.begin(), a.end(), 0LL);

    sort(a.begin(), a.end());
    
    min_dis = max(0LL, a[n] - (max_dis - a[n]));
    if(n == 0){
        min_dis = 0;
    }
    
    if(max_dis * max_dis >= (zx - px) * (zx - px) + (zy - py) * (zy - py) && min_dis * min_dis <= (zx - px) * (zx - px) + (zy - py) * (zy - py)){
        cout << "Yes\n";
    }else{
        
        cout << "No\n";
    }
    return ;
}

signed main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}