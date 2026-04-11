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
#define int long long
#define ll long long
#define endl "\n"
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define printv(v) for(auto& x: (v)) cout << x << " "; cout << endl;
#define maxv(v) *max_element(v.begin(), v.end())
#define minv(v) *min_element(v.begin(), v.end())
#define rep(i, n, m) for(int (i)=(n);(i)<=(m);(i)++)
#define println(a) cout << a << endl;
#define repd(i,n,m) for(int (i)=(n);(i)>=(m);(i)--)

template <typename T, typename Size>
std::vector<T> Vec(Size d1) {
    static_assert(std::is_integral_v<Size>, "Dimension size must be integer");
    return std::vector<T>(d1);
}
template <typename T, typename Size1, typename... Sizes>
auto Vec(Size1 d1, Sizes... dims) {
    static_assert((std::is_integral_v<Size1> && ... && std::is_integral_v<Sizes>),"All dimension sizes must be integers");
    using inner_vector = decltype(Vec<T>(dims...));
    std::vector<inner_vector> result;
    result.reserve(d1);
    for (Size1 i = 0; i < d1; ++i) {
        result.emplace_back(Vec<T>(dims...));
    }
    return result;
}
using namespace std;

const int maxn = 100000 + 5;


void solve(){
    int n, s, x;
    cin >> n >> s >> x;
    vector<int> nums(n);
    rep(i, 0, n - 1){
        cin >> nums[i];
    }
    vector<pair<int, int>> seg;
    int i =0;
    while(i < n){
        if(nums[i] > x){
            i ++;
            continue;
        }
        int j = i;
        bool has_x = false;
        while(j < n && nums[j] <= x){
            if(nums[j] == x){
                has_x = true;
            }
            j ++;
        }
        if(has_x){
            seg.push_back({i, j - 1});
        }
        i = j;

    }
    int ans = 0;
    for(auto& se: seg){
        int L = se.first;
        int R = se.second;
        map<int, int> freqA;
        freqA[0] = 1;
        int prefix = 0;
        int cntA = 0;
        rep(i, L, R){
            prefix += nums[i];
            int target = prefix - s;
            if(freqA.find(target) != freqA.end()) cntA += freqA[target];
            freqA[prefix] ++;
        }
        map<int, int> freqB;
        freqB[0] = 1;
        int prefixB = 0;
        int cntB = 0;
        rep(i, L, R){
            if(nums[i] == x){
                freqB.clear();
                prefixB = 0;
                freqB[0] = 1;
            }else{
                prefixB += nums[i];
                int targetB = prefixB - s;
                if(freqB.find(targetB) != freqB.end()){
                    cntB += freqB[targetB];
                }
                freqB[prefixB]++;
            }

        }
        ans += (cntA - cntB);
    }
    cout << ans << endl;
    return ;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}