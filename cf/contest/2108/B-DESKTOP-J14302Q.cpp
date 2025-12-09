/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-06-18 23:51:51
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-06-19 15:39:27
 * @FilePath: \Codeforces Round 1022 (Div. 2)\B.cpp
 * @Description: 
 * @
 * @Copyright (c) ${Date} by ${115848824+yuyuan12138@users.noreply.github.com}, All Rights Reserved. 
 */
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
    int n, x;
    cin >> n >> x;
    
    int bits = __builtin_popcountll(x);
    if(n <= bits){
        println(x);
        return ;
    }
    if((n - bits) % 2 == 0){
        println(x + n - bits);
        return ;
    }
    if(x == 1){
        println(n + 3);
        return ;
    }
    if(x == 0){
        if(n == 1){
            println(-1);
            return ;
        }
        println(n + 3);return ;
    }
    println((n - bits) / 2 * 2 + 2 + x);

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