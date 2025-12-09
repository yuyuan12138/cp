/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-06-15 14:27:06
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-06-15 14:40:57
 * @FilePath: \Codeforces Round 1029 (Div. 3)\D.cpp
 * @Description: 
 * @
 * @Copyright (c) ${Date} by ${115848824+yuyuan12138@users.noreply.github.com}, All Rights Reserved. 
 */

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> nums[i];
    }
    // - i * a_times - (n - i + 1) * b_times
    int y, x;
    if((nums[1] * 2 - nums[2]) % (n + 1) != 0){
        cout << "NO" << endl;
        return ;
    }
    y = (nums[1] * 2 - nums[2]) / (n + 1);
    x = y - nums[1] + nums[2];
    if(x < 0 || y < 0){
        cout << "NO" << endl;
        return ;
    }
    for(int i = 1; i <= n; i++){
        if((nums[i] - x * i - y * (n - i + 1)) != 0){
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "YES" << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}