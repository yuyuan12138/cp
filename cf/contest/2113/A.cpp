/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-06-15 16:56:43
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-06-15 17:14:32
 * @FilePath: \Codeforces Round 1031 (Div. 2)\A.cpp
 * @Description: 
 * @
 * @Copyright (c) ${Date} by ${115848824+yuyuan12138@users.noreply.github.com}, All Rights Reserved. 
 */
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    if(x > y){
        swap(a, b);swap(x, y);
    }
    int ans = 0;
    if(k >= a){
        int cnt = (k - a) / x + 1;
        ans += cnt;
        k -= cnt * x;
    }
    
    if(k >= b){
        ans += (k - b ) / y + 1;
        k -= ((k - b ) / y + 1) * y;
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t --) solve();
    return 0;
}