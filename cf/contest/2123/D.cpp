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
    string s;
    cin >> s;
    
    int cnt_1 = 0;
    
    for(int i = 0; i < n; i++){
        if(s[i] == '1') cnt_1++;
    }
    if(cnt_1 <= k){
        cout << "Alice\n";
        return ;
    }
    if(2 * k <= n){
        cout << "Bob\n";
        return ;
    }
    int slow = 0;
    int mx_l = 0;
    for(int fast = 0; fast < n; fast++){
        if(s[fast] == '1'){
            slow = fast;
        }
        mx_l = max(fast - slow, mx_l);
    }
    if(mx_l >= k){
        cout << "Bob\n";

    }else{
        cout << "Alice\n";
    }
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}