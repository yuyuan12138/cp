/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-05-10 15:16:29
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-05-10 15:24:59
 * @FilePath: \Codeforces Round 1017 (Div. 4)\C.cpp
 * @Description: 
 * @
 * @Copyright (c) ${Date} by ${115848824+yuyuan12138@users.noreply.github.com}, All Rights Reserved. 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int tot = 0;
    vector<int> result(n * 2);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> result[i + j];
        }
    }
    for(int i = 0; i < 2 * n; i++){
        tot += result[i];
    }
    int need = (1 + 2 * n) * n;
    cout << need - tot << " ";
    for(int i = 0; i < 2 * n - 1; i++){
        cout << result[i] << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}