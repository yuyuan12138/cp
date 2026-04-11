/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-05-20 15:39:06
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-05-20 15:47:15
 * @FilePath: \Codeforces Round 993 (Div. 4)\C.cpp
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
    int m, a, b, c;
    cin >> m >> a >> b >> c;
    int sum = 0;
    sum += min(a, m);
    sum += min(b, m);
    sum += c;
    cout << min(2 * m , sum) << endl;
}

int main(){
    int t;
    cin >> t;
    while(t --) solve();
}