/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-06-15 16:56:43
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-06-15 17:30:41
 * @FilePath: \Codeforces Round 1031 (Div. 2)\B.cpp
 * @Description: 
 * @
 * @Copyright (c) ${Date} by ${115848824+yuyuan12138@users.noreply.github.com}, All Rights Reserved. 
 */
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int w, h, a, b;
    cin >> w >> h >> a >> b;
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 > x2){
        swap(x1, x2);swap(y1, y2);
    }
    bool flag_1 = false, flag_2 = false;
    if(x1 + a <= x2){
        if((x2 - x1 - a) % a == 0){
            // cout << "Yes" << endl;
            // return ;
            flag_1 = true;
        }
        // else{
        //     cout << "No" << endl;
        //     return ;
        // }
    }
    if(y1 > y2){
        swap(x1, x2);swap(y1,y2);
    }
    if(y1 + b <= y2){
        if((y2 - y1 - b) % b == 0){
            flag_2 = true;
        }
        // else{
        //     cout << "No" << endl;
        //     return ;
        // }
    }
    if(flag_1 || flag_2){
        cout << "Yes" << endl;
        return ;
    }
    cout << "No" << endl;
}

int main(){
    int t;
    cin >> t;
    while(t --) solve();
    return 0;
}