/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-05-10 16:13:57
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-05-10 16:34:52
 * @FilePath: \Codeforces Round 1017 (Div. 4)\F.cpp
 * @Description: 
 * @
 * @Copyright (c) ${Date} by ${115848824+yuyuan12138@users.noreply.github.com}, All Rights Reserved. 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define int long long

using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> result(n, vector<int>(m));
    if(m % k == 0){
        int count = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(count == k + 1){
                    count = 1;
                }
                result[i][j] = count;
                count++;
            }
            if(i % 2 == 1){
                int tmp = result[i][0];
                for(int j = 0; j < m - 1; j++){
                    result[i][j] = result[i][j + 1];
                }
                result[i][m - 1] = tmp;
            }
            
        }

    }else{
        int count = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(count == k + 1){
                    count = 1;
                }
                result[i][j] = count;
                count++;
            }
        }
    }
    

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}