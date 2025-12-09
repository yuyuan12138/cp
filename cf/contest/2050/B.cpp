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
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    ll sum1 = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cin >> nums[i];
        if(i % 2){
            sum1+= nums[i];
            cnt++;
        }
    }
    ll sum = accumulate(nums.begin(), nums.end(), 0LL);
    if(sum % n != 0){
        cout << "NO\n";
        return ;
    }
    if(sum1 * (n - cnt)  == (sum - sum1) * cnt){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}