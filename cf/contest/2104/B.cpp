/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-05-11 11:31:41
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-05-11 13:27:32
 * @FilePath: \Educational Codeforces Round 178\B.cpp
 * @Description: 
 * @
 * @Copyright (c) ${Date} by ${115848824+yuyuan12138@users.noreply.github.com}, All Rights Reserved. 
 */

#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

using namespace std;

int sum(vector<int>& v){
    int sum = 0;
    for(auto& x: v){
        sum += x;
    }
    return sum;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto& x: arr) cin >> x;
    vector<int> pre_max(n + 1);
    vector<int> pre_sum(n + 1);
    for(int i = 0; i < n; i++){
        pre_max[i + 1] = max(pre_max[i], arr[i]);
        pre_sum[i + 1] = pre_sum[i] + arr[i];
    }

    for(int i = 1; i <= n; i++){
        cout << pre_max[n - i + 1] + pre_sum[n] - pre_sum[n - i  + 1] << " ";
    }
    cout << endl;

}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}