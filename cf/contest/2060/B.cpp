#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string> 
#include <string.h>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <bitset>
#include <forward_list>
#include <deque>
#include <set>
#include <tuple>
#include <utility>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <chrono>
#include <random>
#include <complex>
#include <functional>
#include <cassert>
#include <climits>
#include <limits>
#include <tuple>
#include <cstdint>
#include <array>

using namespace std;
using data = int;

#define ll long long

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> cards(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> cards[i][j];
    if(n == 1){
        cout << "1\n";
        return ;
    }

    for(int i = 1; i <= n; i++){
        sort(cards[i].begin(), cards[i].end());
    }
    vector<int> first_col = {0};
    for(int i = 1; i <= n; i++){
        first_col.push_back(cards[i][1]);
    }
    vector<int> idx_ = first_col;
    vector<int> idx = first_col;
    sort(idx_.begin(), idx_.end());
    for(int i = 1; i <= n; i++){
        int tmp = idx_[i];
        for(int j = 1; j <= n; j++){
            if(first_col[j] == tmp){
                idx[i] = j;
                break ;
            }
        }
    }
    
    int cur = *max_element(first_col.begin(), first_col.end());
    for(int i = 2; i <= m; i++){
        vector<int> new_arr(n + 1);
        for(int j = 1; j <= n; j++){
            new_arr[j] = cards[idx[j]][i];
        }
        if(new_arr[1] < cur){
            cout << "-1\n";
            return ;
        }
        cur = new_arr[n];
        for(int j = 1; j <= n - 1; j++){
            if(new_arr[j] >= new_arr[j + 1]){
                cout << "-1\n";
                return ;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << idx[i] << " ";
    }
    cout << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}