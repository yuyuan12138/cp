/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-06-17 00:10:44
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-06-17 00:17:51
 * @FilePath: \Codeforces Round 1013 (Div. 3)\A.cpp
 * @Description: 
 * @
 * @Copyright (c) ${Date} by ${115848824+yuyuan12138@users.noreply.github.com}, All Rights Reserved. 
 */
#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto& x: nums) cin >> x;
    int ans = 0;
    vector<int> cnt(10);
    cnt[0] = 3;
    cnt[1] = 1;
    cnt[2] = 2;
    cnt[3] = 1;
    cnt[5] = 1;
    for(int i = 1; i <= n; i++){
        
        cnt[nums[i - 1]] --;
        if(all_of(cnt.begin(), cnt.end(), [](const int b){return b <= 0;})){
            ans = i;
            break;
        }
    }
    cout << ans << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t --) solve();
    return 0;
}