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
    int n; string s; cin >> n; cin >> s;
    if(n == 2){
        if(s[1] == 'B'){
            cout << "Alice" << "\n";
        }else{
            cout << "Bob" << "\n";
        }
        return ;
    }
    if(s[0] == s[n - 1]){
        if(s[0] == 'A'){
            cout << "Alice\n";
        }else{
            cout << "Bob\n";
        }
        return ;
    }
    int cnt_b = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'B') cnt_b ++;
    }
    if((s[n - 1] == 'A' && s[n - 2] == 'A') || cnt_b == 1){
        cout << "Alice\n";
    }else{
        cout << "Bob\n";
    }
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}