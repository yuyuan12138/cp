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
using ll = long long;

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(20, 0);
    for(int i = 0; i < n; i++){
        cnt[s[i] - '0'] += 1;
    }

    ll ans = 0;
    for(int i = 9; i >= 0; i--){
        
        for(int j = i; j <= 9; j++){
            if(cnt[j] > 0){
                cnt[j]--;
                ans = ans * 10 + j;
                break;
            }
        }
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