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

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
using ll = long long;
void solve(){
    int n;
    cin >> n;
    vector<ll> nums(n + 1);
    for(int i = 1; i <= n; i++) cin >> nums[i];
    if(n == 1){
        cout << 0 << "\n";
    }
    if(all_of(nums.begin() + 1, nums.end(), [&](const int x){
        return x == nums[1];
    })){
        cout << 0 << "\n";
        return ;
    }
    ll cost = LLONG_MAX;

    int slow = 1;
    for(int fast = 1; fast <= n; fast++){
        if(nums[slow] != nums[fast]){
            slow = fast;
        }
        cost = min(cost, nums[fast] * (n - fast) + nums[slow] * (slow - 1));
    }
    cout << cost << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}