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

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto& x: nums) cin >> x;
    sort(nums.begin(), nums.end());
    int cnt = 0x3f3f3f3f;
    
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if((nums[j] - nums[i]) % 2 == 0){
                cnt = min(cnt, n - (j - i + 1));
            }
        }
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