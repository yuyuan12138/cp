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
    int n, x;
    cin >> n >> x;
    int cur = 0;
    int bit = 0;
    vector<int> logits(32);
    int tmp = x;
    while(x){
        if(x & 1){
            logits[bit] = 1;
        }
        x >>= 1;
        bit++;
    }
    x = tmp;
    vector<int> ans;

    auto check = [&](int num){
        int bit_ = 0;
        while(num){
            if((num & 1) && (logits[bit_]) || !(num & 1) && !logits[bit_]){
                bit_++;
                num >>= 1;
                continue;
            }
            return false;
        }
        return true;
    };
    int i = 0;
    for(; i < n; i++){
        if(check(cur | i)){
            ans.push_back(i);
            cur |= i;
        }else{
            ans.push_back(cur);
        }
    }
    
    if(cur != x){
        ans[n - 1] = x;
    }
    
    for(auto& x: ans) cout << x << " ";
    cout << "\n";
    

    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}