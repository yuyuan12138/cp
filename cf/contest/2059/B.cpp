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
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    if(k == n){
        for(int i = 2; i <= n; i += 2){
            if(a[i] != i / 2){
                cout << i / 2 << "\n";
                return ;
            }
        }
        cout << k / 2 + 1 << "\n";
    }else{
        for(int i = 2; i <= n - k + 2; i++){
            if(a[i] != 1){
                cout << 1 << "\n";
                return ;
            }
        }
        cout << 2 << "\n";
    }
    

    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}