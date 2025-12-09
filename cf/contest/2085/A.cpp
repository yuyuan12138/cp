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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool is_same = true;
    for(int i = 0; i < n; i++){
        if(s[i] != s[0]) is_same = false;
    }
    if(is_same){
        cout << "NO\n";
        return ;
    }

    if(k >= 1){
        cout << "YES\n";
        return ;
    }
    string s_rev(s.begin(), s.end());
    reverse(s_rev.begin(), s_rev.end());
    for(int i = 0; i < n; i++){
        if(s[i] > s_rev[i]){
            cout << "NO\n";
            return ;
        }
        if(s[i] < s_rev[i]){
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