/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-06-17 14:37:26
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-06-17 15:31:50
 * @FilePath: \Codeforces Round 1019 (Div. 2)\B.cpp
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
#define repd(i,n,m) for(int (i)=(n);(i)>=(m);(i)--)
#define print(a) cout << a << endl;
using namespace std;

const int maxn = 2*100000 + 5;


void solve(){
    int n;
    cin >> n;
    string nums;
    cin >> nums;
    
    nums = "0" + nums;

    int ans = n, cur = nums[0];
    rep(i, 1, n){
        if(cur != nums[i]) ans += 1;
        cur = nums[i];
    }
    if(ans >= 3 + n){
        print(ans - 2);
    }else if(ans == 2 + n){
        print(ans - 1);
    }else{
        print(ans);
    }
    
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