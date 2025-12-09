/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-05-11 11:23:21
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-05-11 11:25:17
 * @FilePath: \Educational Codeforces Round 178\A.cpp
 * @Description: 
 * @
 * @Copyright (c) ${Date} by ${115848824+yuyuan12138@users.noreply.github.com}, All Rights Reserved. 
 */

#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

using namespace std;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    int sum = a + b + c;
    int tmp = sum / 3 * 3;
    if(tmp == sum && tmp / 3 >= a && tmp / 3 >= b){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}
