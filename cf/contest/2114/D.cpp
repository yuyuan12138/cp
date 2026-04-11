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
    ll n; cin >> n;
    vector<pair<ll, ll>> monsters(n + 1);
    vector<ll> x_list(n + 1);
    vector<ll> y_list(n + 1);
    for(int i = 1; i <= n; i++){
        ll x, y; cin >> x >> y;
        monsters[i].first = x;
        monsters[i].second = y;
        x_list[i] = x; y_list[i] = y;
    }
    sort(x_list.begin(), x_list.end());
    sort(y_list.begin(), y_list.end());
    ll ans = LLONG_MAX;
    if(n == 1){
        cout << 1 << "\n";
        return ;
    }
    ll x_max = x_list[n], y_max = y_list[n], x_min = x_list[1], y_min = y_list[1];

    for(int i = 1; i <= n; i++){
        ll x = monsters[i].first, y = monsters[i].second;
        if(x == x_max){
            x_max = x_list[n - 1];
        }
        if(x == x_min){
            x_min = x_list[2];
        }
        if(y == y_max){
            y_max = y_list[n - 1];
        }
        if(y == y_min){
            y_min = y_list[2];
        }
        
        if((x_max - x_min + 1) * (y_max - y_min + 1) == n - 1){
            int tmp = min((x_max - x_min + 1), (y_max - y_min + 1));
            ans = min(ans, n - 1 + tmp);
        }else{
            ans = min(ans, (x_max - x_min + 1) * (y_max - y_min + 1));
        }
        x_max = x_list[n], y_max = y_list[n], x_min = x_list[1], y_min = y_list[1];
    }
    cout << max(ans, n) << "\n";

    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}