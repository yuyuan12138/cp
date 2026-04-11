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
    ll n, x, y; cin >> n >> x >> y;
    vector<ll> nums(n + 1);
    for(int i = 1; i <= n; i++) cin >> nums[i];
    ll sum = accumulate(nums.begin(), nums.end(), 0LL);
    sort(nums.begin(), nums.end());
    ll cnt = 0;
    for(int slow = 1; slow <= n - 1; slow++){
        int l = slow + 1, r = n;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(sum - (nums[mid] + nums[slow]) >= x){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        int left = l;
        l = slow + 1, r = n;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(sum - (nums[mid] + nums[slow]) <= y){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        cnt += max(0, left - r - 1);
    }
    cout << cnt << "\n";

    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}