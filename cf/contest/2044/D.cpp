/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-05-20 15:44:20
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-05-20 16:16:11
 * @FilePath: \Codeforces Round 993 (Div. 4)\D.cpp
 * @Description: 
 * @
 * @Copyright (c) ${Date} by ${115848824+yuyuan12138@users.noreply.github.com}, All Rights Reserved. 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>
#include <map>
#include <string>

using namespace std;

int vis[1000000];

void solve(){
    memset(vis, 0, sizeof(vis));
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> res_num;
    for(auto& x: a) 
    {
        cin >> x;
        vis[x] = 1;
    }
    // int max_elem = *max_element(a.begin(), a.end()) + 1;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            res_num.push_back(i);
        }
    }

    map<int, int> mp;
    vector<int> b(n);
    int idx = 0;
    int mode = 1;
    for(int i = 0; i < a.size(); i++){


        if(mp[a[i]] == mode){
            b[i] = res_num[idx];
            idx += 1;
            if(idx == res_num.size()){
                idx = 0;
            }
        }else{
            b[i] = a[i];

            if(mp.find(a[i]) != mp.end()){
                mp[a[i]] ++;
                mode = max(mp[a[i]], mode);
            }else{
                mp[a[i]] = 1;
            }
        }

        
    }

    for(int i = 0; i < n; i++){
        cout << b[i] << " ";
    }

    cout << endl;

}

int main(){
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t -- ) solve();
    return 0;
}