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
    for(int i = 1; i <= n; i++){
        cin >> nums[i];
    }
    vector<ll> pre_max(n + 1);
    vector<ll> pre_small(n + 1);
    pre_max[1] = pre_small[1] = nums[1];
    int max_num = nums[1];
    ll small_num = nums[1];
    for(int i = 2; i <= n; i++){
        max_num = min(small_num, nums[i]);
        small_num += max_num;
        pre_max[i] = max_num;
        pre_small[i] = small_num;
    }
    ll ans = pre_small[n];
    for(int i = 1; i <= n - 1; i++){
        if(i == 1){
            ans = min(ans, nums[i] + nums[i + 1]);
            continue;
        }
        ans = min(ans, pre_small[i - 1] + min(pre_max[i - 1], nums[i] + nums[i + 1]));
    }
    cout << ans << "\n";
    
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}