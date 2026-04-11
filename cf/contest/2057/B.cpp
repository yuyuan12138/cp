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
    for(int i = 1; i <= n; i++){
        cin >> nums[i];
    }
    map<int, int> cnt; // num cnt;
    for(int i = 1; i <= n; i++){
        if(cnt.find(nums[i]) == cnt.end()){
            cnt[nums[i]] = 0;
        }
        cnt[nums[i]]++;
    }
    vector<pair<int, int>> cnt_v;
    for(auto it = cnt.begin(); it != cnt.end(); it++){
        cnt_v.push_back({it->first, it->second});
    }
    auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
        return a.second < b.second;
    };
    sort(cnt_v.begin(), cnt_v.end(), cmp);
    
    int ans = cnt_v.size();
    for(int i = 0; i < cnt_v.size(); i++){
        if(k >= cnt_v[i].second){
            k -= cnt_v[i].second;
            ans -= 1;
        }else{
            break;
        }
    }
    cout << max(ans, 1) << "\n";

    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}