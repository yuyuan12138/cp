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
    vector<ll> nums(n + 1);
    for(int i = 1; i <= n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());
    // 
    vector<ll> new_nums;
    bool flag = false;
    ll mx = 0;
    for(int i = n; i >= 1; i--){
        if(nums[i] == nums[i - 1] && !flag){
            mx = nums[i];
            flag = true;
            i --;
            continue;
        }
        new_nums.push_back(nums[i]);
    }
    if(!flag){
        cout << -1 << "\n";
        return ;
    }
    reverse(new_nums.begin(), new_nums.end());
    int m = new_nums.size();

    for(int i = 0; i <= m - 2; i++){
        int l = i + 1, r = m;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(new_nums[i] + 2 * mx > new_nums[mid]){
                cout << new_nums[i] << " " << mx << " " << mx << " " << new_nums[mid] << "\n";
                return ;
            }else{
                r = mid - 1;
            }
        }
    }
    cout << -1 << "\n";

    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}