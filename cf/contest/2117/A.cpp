/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-06-14 23:50:57
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-06-14 23:55:41
 * @FilePath: \Codeforces Round 1029 (Div. 3)\A.cpp
 * @Description: 
 * @
 * @Copyright (c) ${Date} by ${115848824+yuyuan12138@users.noreply.github.com}, All Rights Reserved. 
 */

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for(auto& x: nums) cin >> x;
    int l = 0, r= 0;
    for(int i = 0; i < n; i++){
        if(nums[i] == 1){
            l = i;
            break;
        }
    }
    for(int i = n - 1; i >= 0; i--){
        if(nums[i] == 1){
            r = i;
            break;
        }
    }
    if(r - l + 1 > x){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
