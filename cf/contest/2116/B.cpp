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
template<typename T>
T power_with_mod(T base, T exp, T mod) {
    if(exp == 0) return 1;
    if(exp == 1) return base;
    if(exp % 2){
        return (power_with_mod(base, exp / 2, mod) % mod) * (power_with_mod(base, exp / 2, mod) % mod) * base % mod;
    }
    return (power_with_mod(base, exp / 2, mod) % mod) * (power_with_mod(base, exp / 2, mod) % mod) % mod;
}

void solve(){
    const int MOD = 998244353;
    int n; cin >> n;
    vector<int> q(n);
    vector<int> p(n);
    for(auto& x: q) cin >> x;
    for(auto& x: p) cin >> x;

    vector<int> num_idx_q(n);
    vector<int> num_idx_p(n);
    for(int i = 0; i < n; i++){
        num_idx_p[p[i]] = i;
        num_idx_q[q[i]] = i;
    }

    vector<int> pre_max_q(n);
    vector<int> pre_max_p(n);
    pre_max_q[0] = q[0], pre_max_p[0] = p[0];
    for(int i = 1; i < n; i++){
        pre_max_p[i] = max(pre_max_p[i - 1], p[i]);
        pre_max_q[i] = max(pre_max_q[i - 1], q[i]);
    }

    for(int i = 0; i <= n - 1; i++){

        int mx_n = max(pre_max_q[i], pre_max_p[i]);

        ll ans = 0LL;
        if(pre_max_q[i] == pre_max_p[i]){
            if(q[i - num_idx_p[mx_n]] > p[i - num_idx_q[mx_n]]){
                ans = (ll)(power_with_mod(2, q[i - num_idx_p[mx_n]], MOD) + power_with_mod(2, mx_n, MOD)) % MOD;
            }else{
                ans = (ll)(power_with_mod(2, p[i - num_idx_q[mx_n]], MOD) + power_with_mod(2, mx_n, MOD)) % MOD;
            }
            cout << ans << " ";
            continue;
        }
        if(mx_n == pre_max_q[i]){
            ans = (ll)(power_with_mod(2, p[i - num_idx_q[mx_n]], MOD) + power_with_mod(2, mx_n, MOD)) % MOD;
        }else{
            ans = (ll)(power_with_mod(2, q[i - num_idx_p[mx_n]], MOD) + power_with_mod(2, mx_n, MOD)) % MOD;
        }
        
        cout << ans << " ";
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