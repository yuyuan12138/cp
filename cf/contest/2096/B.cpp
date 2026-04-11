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
    int n, k; cin >> n >> k;
    vector<int> l(n);
    vector<int> r(n);
    for(auto& x: l) cin >> x;
    for(auto& x: r) cin >> x;

    // consider the worst case
    ll worst_sum = 0;
    vector<ll> store(n);
    for(int i = 0; i < n; i++){
        worst_sum += max(l[i], r[i]);
        store[i] = min(l[i], r[i]);
    }
    sort(store.begin(), store.end());
    for(int i = n - 1; i >= n - k + 1; i--){
        worst_sum += store[i];
    }
    cout << worst_sum + 1 << "\n";

}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}