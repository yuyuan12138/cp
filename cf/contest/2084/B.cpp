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
    ll n;
    cin >> n;
    vector<ll> nums(n);
    for(auto& x: nums) cin >>x;
    sort(nums.begin(), nums.end());
    int cnt = 0;
    vector<ll> store;
    bool is_eq = false;
    for(int i = 1; i < n; i++){
        if(nums[i] == nums[0]) is_eq = true;
        if(gcd(nums[0], nums[i]) == nums[0]){
            store.push_back(nums[i]);
        }
    }
    if(store.size() == 0){
        cout << "NO\n";
        return ;
    }
    ll tmp = store[0];
    for(int i = 1; i < store.size(); i++){
        tmp = gcd(tmp, store[i]);
    }
    if(tmp <= nums[0] || is_eq){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }

    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}