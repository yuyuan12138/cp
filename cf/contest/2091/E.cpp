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

template<typename T>
vector<T> eratosthenes(const T n){
    vector<T> primes;
    vector<bool> is_primes(n + 1, true);
    for(T i = 2; i <= n; i++){
        if(is_primes[i]){
            primes.push_back(i);
            for(T j = i * 2; j <= n; j += i){
                is_primes[j] = false;
            }
        }
    }
    return primes;
}

void solve(){
    int n; cin >> n;
    int cnt = 0;
    auto primes = eratosthenes(n);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < primes.size(); j++){
            if(primes[j] * i <= n){
                cnt++;
            }else{
                break;
            }
        }
    }
    cout << cnt << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}