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
    int x; cin >> x;
    int a1 = 0, a2 = 0, a3 = 0;
    int cnt = 0;
    while(true){
        if(a1 == x && a2 == x && a3 == x){
            cout << cnt << "\n";
            return ;
        }
        if(a1 <= a2 && a1 <= a3){
            a1 = min(min(a2, a3) * 2 + 1, x);
            cnt += 1;
        }else if(a2 <= a1 && a2 <= a3){
            a2 = min(x, min(a1, a3) * 2  + 1);
            cnt += 1;
        }else{
            a3 = min(x, min(a2, a1) * 2 + 1);
            cnt += 1;
        }
    }
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}