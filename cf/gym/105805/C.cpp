/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-04-03 11:15:04
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-04-03 11:32:54
 * @FilePath: \cf\TheForces Round #41 (Magical-Forces)\C.cpp
 * @Description: 
 * @
 * @Copyright (c) ${Date} by ${115848824+yuyuan12138@users.noreply.github.com}, All Rights Reserved. 
 */

#include <bits/stdc++.h>

using namespace std;

int arr[2 * 100000 + 10];

void solve(){
    long long n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    if(n >= 5){ cout << "Yes" << endl; return;};
    bool flag = true;
    for(long long i = 0; i< n; i++){
        if(arr[i] % 2 != (i + 1) % 2){
            flag = false;
        }
    }
    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}