/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-05-20 15:44:23
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-05-20 16:29:48
 * @FilePath: \Codeforces Round 993 (Div. 4)\E.cpp
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

#define ll long long

void solve(){
    ll k, l1, l2, r1, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    ll kn = 1, ans = 0;
    for(int n = 0; r2 / kn >= l1; n++){
        ans += max(0ll, min(r2 / kn, r1) - max((l2 - 1) / kn + 1, l1) + 1ll);
        kn *= k;
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t --) solve();
}