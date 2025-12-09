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
    int n; cin >> n;
    vector<pair<int, int>> p(n + 1);
    vector<int> re_num(2 * n + 1);
    vector<int> re_num_binary(2 * n + 1);
    for(int i = 1; i <= n; i++){
        cin >> p[i].first >> p[i].second;
        if(p[i].first == p[i].second){
            re_num[p[i].first] += 1;
            re_num_binary[p[i].first] = 1;
        }
    }

    vector<int> prefix_sum(2 * n + 2);
    for(int i = 1; i <= 2 * n; i++){
        prefix_sum[i] = prefix_sum[i - 1] + re_num_binary[i];
    }


    for(int i = 1; i <= n; i++){
        if(p[i].first == p[i].second){
            if(re_num[p[i].first] >= 2)
                cout << 0;
            else cout << 1;
            continue;
        }
        int l = p[i].first, r = p[i].second;
        int cnt = 0;
        // for(int j = l; j <= r; j++){
        //     if(re_num[j] == 0){
        //         cnt++;
        //     }
        // }
        if(prefix_sum[r] - prefix_sum[l - 1] < r - l + 1){
            cout << 1;
        }else{
            cout << 0;
        }
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