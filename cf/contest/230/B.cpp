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

template<typename T>
bool is_prime(const T num){
    if (num <= 1) {
        return false;
    }
    if (num == 2){
        return true;
    }
    for(T divisor = 2; divisor * divisor <= num; divisor++){
        if(num % divisor == 0){
            return false;
        }
    }
    return true;
}



void solve(){
    ll n; cin >> n;
    
    ll left = 2, right = min(n, 1000000LL);
    while (left <= right)
    {
        ll mid = (left + right) / 2;
        if(mid * mid  == n && is_prime(mid)){
            cout << "YES\n";
            return ;
        }
        if(mid * mid < n){
            left = mid + 1;
        }else{
            right = mid - 1;
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