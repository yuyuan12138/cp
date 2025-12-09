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
    int n, m, k; cin >> n >> m >> k;
    
    vector<int> a(n + 1);
    for(int i = 1; i <= m; i++) {
        int q; cin >> q;
        a[i] = q;
    }
    
    vector<int> known(n + 1);
    for(int i = 1; i <= k; i++){
        int tmp;
        cin >> tmp;
        known[tmp] = 1;
    }
    if(k == n){
        cout << string(m, '1') << "\n";
        return ;
    }
    if(k <= n - 2){
        cout << string(m, '0') << "\n";
        return ;
    }
    int val = -1;
    for(int i = 1; i <= n; i++){
        if(known[i] == 0){
            val = i;
            break;
        }
    }
    for(int i = 1; i <= m; i++){
        if(a[i] == val){
            cout << 1;
        }else{
            cout << 0;
        }
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