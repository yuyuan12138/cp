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
    vector<ll> a(n + 1);
    // vector<ll> prefix_sum(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    vector<ll> prefix_sum(n + 2);
    for(int i = 1; i <= n; i++)
        if(a[i] > 0LL)
            prefix_sum[i] = prefix_sum[i - 1] + a[i];
        else
            prefix_sum[i] = prefix_sum[i - 1];

    vector<ll> suffix_sum(n + 2);

    for(int i = n; i >= 1; i--)
        if(a[i] < 0LL)
            suffix_sum[i] = suffix_sum[i + 1] - a[i];
        else  
            suffix_sum[i] = suffix_sum[i + 1];
    
    ll ans = 0LL;
    for(int i = 0; i <= n; i++){
        ans = max(ans, prefix_sum[i] + suffix_sum[i + 1]);
    }
    cout << ans << "\n";

    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}