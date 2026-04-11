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

int fib[20];

void init(){
    fib[1] = 1; fib[2] = 2;
    for(int i = 3; i <= 15; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        vector<int> arr(3);
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr.begin(), arr.end());
        if(fib[n] + fib[n - 1] <= arr[2] && fib[n] <= arr[1] && fib[n] <= arr[0]){
            cout << 1;
        }else{
            cout << 0;
        }
    }
    cout << "\n";
    return ;
}

int main() {
    speedup();
    init();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}