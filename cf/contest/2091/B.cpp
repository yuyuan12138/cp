/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-06-17 00:10:48
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-06-17 00:26:45
 * @FilePath: \Codeforces Round 1013 (Div. 3)\B.cpp
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
    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    int idx = 0;
    int ans = 0;
    int cnt = 0;
    int min_num = 0x3f3f3f3f;
    while(idx != n){
        cnt += 1;
        if (min_num > nums[idx]){
            min_num = nums[idx];
        }
        if(cnt * min_num >= x){
            ans += 1;
            min_num = 0x3f3f3f3f;
            cnt = 0;
        }
        idx += 1;
    }
    cout << ans << "\n";
}

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
}