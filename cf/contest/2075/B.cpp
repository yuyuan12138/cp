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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(k > 1){
        sort(a.begin(), a.end());
        ll ans = 0;
        for(int i = n; i >= n - k; i--){
            ans += a[i];
        }
        cout << ans << "\n";
    }else{
        int l = *max_element(a.begin() + 2, a.end());
        int r = *max_element(a.begin() + 1, a.end() - 1);
        cout << max(l + a[1], r + a[n]) << "\n";
    }
    return ;
}

int main() {
    speedup();
    int32_t t; cin >> t;
    while(t--) solve();
    return 0;
}