/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-05-09 18:46:11
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-05-09 19:15:03
 * @FilePath: \Codeforces Round 1020 (Div. 3)\C.cpp
 * @Description: 
 * @
 * @Copyright (c) ${Date} by ${115848824+yuyuan12138@users.noreply.github.com}, All Rights Reserved. 
 */
#include <bits/stdc++.h>

using namespace std;


void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);
    for(auto& x: a) cin >> x;
    for(auto& x: b) cin >> x;
    
    bool is_all_negative = all_of(b.begin(), b.end(), [](const int b_idx){ return b_idx == -1; });
    if(is_all_negative){
        int min_a = *min_element(a.begin(), a.end());
        int max_a = *max_element(a.begin(), a.end());
        int max_x = min_a + k;
        cout << max_x - max_a + 1 << endl;
        return ;
    }

    // find the x
    int x = 0;
    for(int i = 0; i < n; i++){
        if(b[i] != -1){
            x = b[i] + a[i];
            break;
        }
    }

    // check if legal
    for(int i = 0; i < n; i++){
        if(b[i] != -1){
            if(a[i] + b[i] != x){
                cout << 0 << endl;
                return ;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(b[i] == -1){
            if(x - a[i] <= k && x - a[i] >= 0){
                continue;
            }
            cout << 0 << endl;
            return ;
        }
    }
    cout << 1 << endl;


}

int main(){
    int t;
    cin >> t;
    while(t -- )solve();
    return 0;
}