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
    ll n, k, p;
    cin >> n >> k >> p;
    k = abs(k);
    if(p * n < k){
        cout << -1 << "\n";
        return ;
    }
    if(k % p == 0){
        cout << k / p << "\n";
    }else{
        cout << k / p + 1 << "\n";
    }
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}