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

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    // 101 010
    int n, k;
    cin >> n >> k;
    if(n == k){
        cout << string(n, '1') << "\n";
        return ;
    }
    int cnt1 = k, cnt0 = n - k;
    if(cnt1 == cnt0){
        string res = "";
        for(int i = 1; i <= cnt1; i++){
            res += "10";
        }
        cout << res << "\n";
        return ;
    }
    int t = min(cnt1, cnt0);
    string res = "";
    for(int i = 1; i <= t / 2; i++){
        res += "10";
    }
    string tmp = "";
    if(cnt1 > cnt0){
        for(int i = 1; i <= cnt1 - cnt0; i++){
            tmp += "1";
        }
    }else{
        for(int i = 1; i <= cnt0 - cnt1; i++){
            tmp += "0";
        }
    }
    if(t % 2 == 1){
        tmp = "1" + tmp + "0";
    }
    res = res + tmp + res;
    cout << res << "\n";
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}