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
    int n; string a, b;
    cin >> n;
    cin >> a;
    cin >> b;
    // a 0 and 1
    int cnta0 = 0, cnta1 = 0;
    int cntb0 = 0, cntb1 = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            if(a[i] == '1'){
                cnta0++;
            }
            if(b[i] == '1'){
                cntb0++;
            }
        }else{
            if(a[i] == '1'){
                cnta1 ++;
            }
            if(b[i] == '1'){
                cntb1++;
            }
        }
    }
    
    if(cnta0 + cntb1 <= n / 2 && cnta1 + cntb0 <= n - n / 2){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }


    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}