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

    vector<int> digit_cnt_1(32);
    int max_bit = 0;
    for(int i = 1; i <= n; i++){
        int tmp = nums[i];
        int bit = 0;
        while(tmp){
            if(tmp & 1){
                digit_cnt_1[bit] += 1;
            }
            bit++;
            tmp >>= 1;
        }
        max_bit = max(max_bit, bit);
    }

    ll ans = 0;
    
    for(int i = 1; i <= n; i++){
        ll cnt = 0;
        ll tmp = nums[i];
        int bit = 0;
        for(int _ = 0; _ < max_bit; _++){
            if(tmp & 1){
                cnt += (ll)pow(2, bit) * (n - digit_cnt_1[bit]);
            }else{
                cnt += (ll)pow(2, bit) * digit_cnt_1[bit];
            }
            bit++;
            tmp >>= 1;
        }
        

        ans = max(ans, cnt);
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