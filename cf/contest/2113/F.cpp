/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-06-15 18:23:12
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-06-15 18:44:48
 * @FilePath: \Codeforces Round 1031 (Div. 2)\F.cpp
 * @Description: 
 * @
 * @Copyright (c) ${Date} by ${115848824+yuyuan12138@users.noreply.github.com}, All Rights Reserved. 
 */
#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(auto& x: a) cin >> x;
    for(auto& x: b) cin >> x;
    set<int> seen_a, seen_b;
    vector<int> res_a(n);
    vector<int> res_b(n);
    
    for(int i = 0; i < n; i++){
        if(a[i] == b[i]){
            res_a[i] = a[i];
            res_b[i] = b[i];
            seen_a.insert(b[i]);
            seen_b.insert(a[i]);
            continue;
        }
        bool flaga_a = false, flaga_b = false;
        bool flagb_a = false, flagb_b = false;
        if(seen_a.count(a[i])) flaga_a = true;
        if(seen_b.count(b[i])) flagb_b = true;
        if(seen_a.count(b[i])) flagb_a = true;
        if(seen_b.count(a[i])) flaga_b = true;
        
        if(flaga_a || flagb_b){
            res_a[i] = b[i];
        res_b[i] = a[i];
        seen_a.insert(b[i]);
        seen_b.insert(a[i]);
            
            continue;
        }
        res_a[i] = a[i];
            res_b[i] = b[i];
            seen_a.insert(a[i]);
            seen_b.insert(b[i]);
        
        
    }
    cout << seen_a.size() + seen_b.size() << endl;
    for(auto& x: res_a){
        cout << x << " ";
    }
    cout << endl;
    for(auto& x: res_b){
        cout << x << " ";
    }
    cout << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}