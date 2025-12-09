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
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for(int i = 1; i <= n; i++) cin >> nums[i];
    int cnt_odd = 0;
    vector<int> odds;
    vector<int> evens;

    for(int i = 1; i <= n; i++){
        if(nums[i] % 2){
            cnt_odd ++;
            odds.push_back(nums[i]);
        }else{
            evens.push_back(nums[i]);
        }
    }
    int cnt_even = n - cnt_odd;

    ll sum = accumulate(nums.begin(), nums.end(), 0LL);
    if(cnt_even == 0 || cnt_odd == 0){
        cout << *max_element(nums.begin(), nums.end()) << "\n";
        return ;
    }
    cout << sum - (cnt_odd - 1) << "\n";
    

    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}