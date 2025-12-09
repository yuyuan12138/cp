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
    int n; cin >> n;
    vector<ll> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    if(n == 1){
        cout << nums[0] << "\n";
        return ;
    }
    // int ans = 0;
    auto dfs = [](auto&& dfs, vector<ll>& nums) -> ll {
        if(nums.size() == 1){
            return nums[0];
        }
        ll sum = accumulate(nums.begin(), nums.end(), 0LL);
        vector<ll> diff(nums.size() - 1);
        // vector<int> neg_diff(nums.size() - 1);
        for(int i = 0; i < nums.size() - 1; i++){
            diff[i] = nums[i + 1] - nums[i];
            // neg_diff[i] = nums[i] - nums[i + 1];
        }
        ll tmp = abs(nums[nums.size() - 1] - nums[0]);
        // return max(tmp, max(sum, max(dfs(dfs, diff), dfs(dfs, neg_diff))));
        ll t = dfs(dfs, diff);
        
        return max(tmp, max(sum, t));
    };
    ll ans = dfs(dfs, nums);
    cout << ans << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}