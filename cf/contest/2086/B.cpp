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
    ll n, k, x;
    cin >> n >> k >> x;
    vector<int> nums(n + 1);
    for(size_t i = 1; i <= n; i++)
        cin >> nums[i];
    
    ll sum = accumulate(nums.begin(), nums.end(), 0LL);
    if(sum * k < x){
        cout << "0\n";
        return ;
    }
    int cnt = 0;

    while(x > sum){
        x -= sum;
        cnt += n;
        k -= 1;
    }
    if(k == 0){
        cout << 1 << "\n";
        return ;
    }
    size_t idx = n;
    for(; idx >= 1; idx--){
        x -= nums[idx];
        if(x <= 0){
            break;
        }
    }

    cout << (k - 1) * n + idx << "\n";

    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}