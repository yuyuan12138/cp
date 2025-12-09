/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-05-20 15:39:06
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-05-20 15:44:10
 * @FilePath: \Codeforces Round 993 (Div. 4)\B.cpp
 * @Description: 
 * @
 * @Copyright (c) ${Date} by ${115848824+yuyuan12138@users.noreply.github.com}, All Rights Reserved. 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>

using namespace std;

void solve(){
    string s;
    cin >> s;
    int n = s.size();

    for(int i = n - 1; i >= 0; i--){
        if(s[i] == 'p'){
            cout << 'q';
        }else if(s[i] == 'q'){
            cout << 'p';
        }else{
            cout << 'w';
        }
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t --) solve();
}