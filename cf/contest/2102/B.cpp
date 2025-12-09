/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-05-13 16:13:41
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-05-13 16:20:17
 * @FilePath: \Codeforces Round 1024 (Div. 2)\B.cpp
 * @Description: 
 * @
 * @Copyright (c) ${Date} by ${115848824+yuyuan12138@users.noreply.github.com}, All Rights Reserved. 
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct p{
    int val, idx;
};

bool cmp(const p& a, const p& b){
    return a.val < b.val;
}

void solve(){
    int n;
    cin >> n;
    vector<p> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].val;
        a[i].val = abs(a[i].val);
        a[i].idx = i;
    }
    sort(a.begin(), a.end(), cmp);

    vector<int> res(n);

    for(int i = 0; i < n / 2 + 1; i++){
        res[a[i].idx] = 1;
    }
    
    if(res[0]){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl; 
    }
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}

