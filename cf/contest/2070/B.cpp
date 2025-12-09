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
    ll n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;
    // judge if i can get there
    ll cur = x;
    bool flag = false;
    ll time = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'L'){
            cur -= 1;
        }else{
            cur += 1;
        }
        time++;
        if(cur == 0){
            flag = true;
            break;
        }
    }
    if(!flag || time > k){
        cout << "0\n";
        return ;
    }
    ll cnt = 1;
    k -= time;
    time = 0;
    flag = false;
    for(int i = 0; i < n; i++){
        if(s[i] == 'L'){
            cur -= 1;
        }else{
            cur += 1;
        }
        time++;
        if(cur == 0){
            flag = true;
            break;
        }
    }
    if(!flag || time > k){
        cout << "1\n";
        return ;
    }
    cnt += k / time;
    cout << cnt << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}