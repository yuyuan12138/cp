/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-04-03 11:15:04
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-04-03 11:28:32
 * @FilePath: \cf\TheForces Round #41 (Magical-Forces)\B.cpp
 * @Description: 
 * @
 * @Copyright (c) ${Date} by ${115848824+yuyuan12138@users.noreply.github.com}, All Rights Reserved. 
 */

#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long n = 0;
    cin >> n;
    if (n % 2 == 1) {
        cout << 0 << endl;
        return ;
    }
    long long count = 0;
    while(n % 2 == 0){
        n /= 2;
        count++;
    }
    cout << count / 2 << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}