/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-05-13 16:02:00
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-05-13 16:13:00
 * @FilePath: \Codeforces Round 1024 (Div. 2)\.cph\A.cpp
 * @Description: 
 * @
 * @Copyright (c) ${Date} by ${115848824+yuyuan12138@users.noreply.github.com}, All Rights Reserved. 
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve(){
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    if(n % p == 0 && n / p * q != m){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }

    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}
