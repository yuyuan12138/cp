/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-06-15 16:56:43
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-06-15 18:54:13
 * @FilePath: \Codeforces Round 1031 (Div. 2)\C.cpp
 * @Description: 
 * @
 * @Copyright (c) ${Date} by ${115848824+yuyuan12138@users.noreply.github.com}, All Rights Reserved. 
 */

#include <bits/stdc++.h>

using namespace std;

int inrect(int x1, int y1, int x2, int y2, vector<vector<int>>& pref){
    if(x1 > x2 || y1 > y2) return 0;
    return pref[x2 + 1][y2 + 1] - pref[x1][y2 + 1] - pref[x2 + 1][y1] + pref[x1][y1];
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> grids(n);
    for(int i = 0; i < n; i++){
        cin >> grids[i];
    }
    vector<vector<int>> pref(n + 1, vector<int>(m + 1));
    int tot = 0;
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            int add = (grids[i][j] == 'g');
            tot += add;
            pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + add;
        }
    }

    int bl = INT_MAX;
    int inner = k - 1;
    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            if(grids[x][y] == '.'){
                int x1 = max(0, x-inner);
                int x2 = min(n - 1, x + inner);
                int y1 = max(0, y - inner);
                int y2 = min(m - 1, y + inner);
                int l = inrect(x1, y1, x2, y2, pref);
                bl = min(bl, l);
            }
        }
    }
    cout << tot - bl << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t --) solve();
    return 0;
}