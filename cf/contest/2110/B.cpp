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
    string s;
    cin >> s;
    int n = s.size();
    if(n == 2){
        cout << "NO\n";
        return ;
    }
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n - 1; i++){
        if(s[i] == '('){
            cnt1++;
        }else{
            cnt2++;
        }
        if(cnt1 == cnt2){
            cout << "YES\n";
            return ;
        }
    }
    cout << "NO\n";
    
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}