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
    string s;
    cin >> s;
    int n = s.size();
    int sum = 0;
    int cnt_2 = 0;
    int cnt_3 = 0;
    for(int i = 0; i < n; i++){
        sum += s[i] - '0';
        if(s[i] - '0' == 2){
            cnt_2++;
        }
        if(s[i] - '0' == 3){
            cnt_3++;
        }
    }
    int last = sum % 9;
    if(last == 0){
        cout << "YES\n";
        return ;
    }
    for(int i = 0; i <= cnt_2; i++){
        for(int j = 0; j <= cnt_3; j++){
            if((i * 2 + j * 6 + last) % 9 == 0){
                cout << "YES\n";
                return ;
            }
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