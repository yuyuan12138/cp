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

#define ll long long


inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> b(m + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    if(n == 1){
        cout << "YES\n";
        return ;
    }
    sort(b.begin(), b.end());

    // vector<vector<int>> grid(n + 1, vector<int>(m + 2));
    // for(int i = 1; i <= n; i++){
    //     bool flag = false;
    //     for(int j = 1; j <= m + 1; j++){
    //         if(j == m + 1 && !flag){
    //             grid[i][j] = a[i];
    //             break;
    //         }
    //         if(b[j] - a[i] >= a[i] && !flag){
    //             grid[i][j] = a[i];
    //             j++;
    //             flag = true;
    //         }
            
    //         grid[i][j] = b[j - flag] - a[i];
    //     }
    // }
    int cur = min(a[1], b[1] - a[1]);
    auto check = [&](int x){
        if(x >= cur){
            return true;
        }else{
            return false;
        }
    };
    for(int i = 2; i <= n; i++){
        int l = 1, r = m;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(check(b[mid] - a[i])){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        if(l == m + 1 && a[i] < cur){
            cout << "NO\n";
            return ;
        }
        if(a[i] < cur){
            cur = b[l] - a[i];
        }else if(l == m + 1){
            cur = a[i];
        }else{
            cur = min(a[i], b[l] - a[i]);
        }
    }
    cout << "YES\n";
    return ;
}

signed main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}