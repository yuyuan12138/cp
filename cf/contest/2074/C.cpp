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
#define int long long

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    int n;
    cin >> n;
    int tmp = n;
    vector<int> bits(80);
    int bit = 0;
    int cnt_0 = 0, cnt_1 = 0;
    while(n){
        if(n & 1){
            cnt_1++;
            bits[bit] = 1;
        }else{
            cnt_0++;
        }
        bit++;
        n >>= 1;
    }

    if(cnt_0 == 0 || cnt_1 == 1){
        cout << -1 << "\n";
        return ;
    }

    vector<int> ans(bit);
    int flag_0 = false, flag_1 = false;
    

    for(int i = bit - 1; i >= 0; i--){
        if(bits[i] == 1 && !flag_1){
            ans[i] = 0;
            flag_1 = true;
            continue;
        }
        if(bits[i] == 0 && !flag_0){
            ans[i] = 1;
            flag_0 = true;
            continue;
        }
        ans[i] = bits[i];
    }
    int results = 0;
    for(int i = bit - 1; i >= 0; i--){
        results <<= 1;
        results += ans[i];
    }
    cout << results << "\n";
    return ;
}

signed main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}