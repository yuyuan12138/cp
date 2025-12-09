/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-05-09 18:40:45
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-05-09 18:50:46
 * @FilePath: \Codeforces Round 1020 (Div. 3)\B.cpp
 * @Description: 
 * @
 * @Copyright (c) ${Date} by ${115848824+yuyuan12138@users.noreply.github.com}, All Rights Reserved. 
 */
#include <bits/stdc++.h>

using namespace std;


void solve(){
    int n, x;
    cin >> n >> x;
    
    for(int i = 0; i < n; i++){
        if (i == x){
            continue;
        }
        cout << i << " ";
    }
    if(n != x) cout << x << endl;
    else cout << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t -- )solve();
    return 0;
}

