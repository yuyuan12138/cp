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
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    auto dfs = [](auto&& dfs, const vector<int>& a, vector<bool>& vis, int idx, int& cnt, vector<int>& tmp){
        if(vis[idx]){
            return ;
        }else{
            cnt++;
            vis[idx] = true;
            tmp.push_back(idx);
            dfs(dfs, a, vis, a[idx], cnt, tmp);
        }
    };
    vector<bool> vis(n + 1, false);
    vector<int> mp;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int q; cin >> q;
        vector<int> tmp;
        dfs(dfs, a, vis, q, cnt, tmp);
        cout << cnt << " ";
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