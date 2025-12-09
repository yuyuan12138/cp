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
    vector<int> cnt(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> nums[i];
        cnt[nums[i]]++;
    }

    vector<int> sort_nums = nums;
    sort(sort_nums.begin(), sort_nums.end());
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        if(sort_nums[i] == nums[i]){
            continue;
        }else{
            ans.push_back(nums[i]);
        }
    }

    
    if(ans.size() == 0){
        cout << "NO\n";
        return ;
    }else{
        cout << "YES\n";
    }
    cout << ans.size() << "\n";
    for(auto& x: ans){
        cout << x << " ";
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