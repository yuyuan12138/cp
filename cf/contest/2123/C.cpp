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
    vector<int> nums(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> nums[i];
    }
    if(n == 2){
        cout << "11\n";
        return ;
    }
    int min_val = *min_element(nums.begin() + 1, nums.end());
    int max_val = *max_element(nums.begin() + 1, nums.end());
    vector<char> ans(n + 1, '0');
    ans[1] = '1';
    ans[n] = '1';
    int cur_min = 0x3f3f3f3f;
    for(int i = 2; i <= n - 1; i++){
        cur_min = min(cur_min, nums[i - 1]);
        if(nums[i] < cur_min){
            ans[i] = '1';
        } 
    }
    int cur_max = 0;
    for(int i = n - 1; i >= 2; i--){
        cur_max = max(cur_max, nums[i + 1]);
        if(nums[i] > cur_max){
            ans[i] = '1';
        }
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i];
    }
    cout << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}