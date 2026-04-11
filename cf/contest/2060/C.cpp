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
    int n, k;
    cin >> n >> k;
    vector<int> nums(n + 1);
    vector<int> cnt(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> nums[i];
        cnt[nums[i]]++;
    }
    // int mx = *max_element(nums.begin(), nums.end());
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(k - i > n || k - i <= 0) continue;
        int tmp = min(cnt[i], cnt[k - i]);
        if(i == k - i){
            cnt[i] -= tmp;
            ans += tmp / 2;
            if(tmp % 2 == 1){
                cnt[i] ++;
            }
        }else{
            cnt[i] -= tmp;
            cnt[k - i] -= tmp;
            
            ans += tmp;
        }
        
        
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