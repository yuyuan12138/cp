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
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> nums(n + 1);
    vector<ll> l_v;
    vector<ll> r_v;
    vector<ll> mid;
    for(int i = 1; i <= n; i++) {
        
        cin >> nums[i];
        if(i < l){
            l_v.push_back(nums[i]);
        }
        if(i > r){
            r_v.push_back(nums[i]);
        }
        if(l <= i && i <= r){
            mid.push_back(nums[i]);
        }
    }
    sort(l_v.begin(), l_v.end());
    sort(r_v.begin(), r_v.end());
    sort(mid.begin(), mid.end());
    ll sum = accumulate(mid.begin(), mid.end(), 0LL);
    int l_v_s = l_v.size(), r_v_s = r_v.size(), m_v_s = mid.size();
    ll sum1 = sum;
    ll sum2 = sum;
    for(int i = 1; i <= min(l_v_s, m_v_s); i++){
        if(mid[m_v_s - i] > l_v[i - 1]){
            sum1 -= mid[m_v_s - i] - l_v[i - 1];
        }else{
            break;
        }
    }
    for(int i = 1; i <= min(r_v_s, m_v_s); i++){
        if(mid[m_v_s - i] > r_v[i - 1]){
            sum2 -= mid[m_v_s - i] - r_v[i - 1];
        }else{
            break;
        }
    }
    cout << min(sum1, sum2) << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}