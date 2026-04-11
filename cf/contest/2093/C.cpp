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

bool is_prime(int n){
    if(n == 1) return false;
    if(n == 2) return true;
    int tmp = sqrt(n);
    for(int i = 2; i <= tmp + 1; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}   

void solve(){
    int x, k; cin >> x >> k;
    
    if(x == 1){
        string tmp(k, '1');
        if(is_prime(stoi(tmp))){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
        return ;
    }

    if(k == 1 && is_prime(x)){
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