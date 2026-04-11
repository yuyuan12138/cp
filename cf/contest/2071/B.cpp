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
    ll n; cin >> n;
    if(n == 1){
        cout << -1 << "\n";
        return ;
    }
    
    auto check = [](const ll x){
        ll tmp = (ll) sqrt(x);
        if(tmp * tmp == x) return true;
        return false;
    };
    if(check((n + 1) * n / 2)){
        cout << -1 << "\n";
        return ;
    }
    cout << "2 1 ";
    for(ll i = 3; i <= n; i++){
        if(check((i + 1) * i / 2)){
            i += 1;
            cout << i << " " << i - 1 << " ";
        }else{
            cout << i << " ";
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