/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-06-14 23:58:22
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-06-15 00:00:31
 * @FilePath: \Codeforces Round 1029 (Div. 3)\B.cpp
 * @Description: 
 * @
 * @Copyright (c) ${Date} by ${115848824+yuyuan12138@users.noreply.github.com}, All Rights Reserved. 
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        cout << 1 << " ";
        for(int i = n; i >= 2; i--){
            cout << i << " ";
        }
        cout << endl;
    }
}