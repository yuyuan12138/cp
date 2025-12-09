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
#define all(x) (x).begin(), (x).end()

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    if(s == "sp"){
        cout << "YES\n";
        return ;
    }
    int cnt_s = 0;
    int cnt_p = 0;
    bool has_p = false;
    for(int i = 0; i < n; i++){
        if(s[i] == 's') cnt_s++;
        else if(s[i] == 'p') cnt_p++;
        if(has_p && s[i] == 's'){
            cout << "NO\n";
            return ;
        }
        if(s[i] == 'p'){
            has_p = true;
        }
    }
    if(cnt_s == 0 || cnt_p == 0){
        cout << "YES\n";
        return ;
    }

    if(cnt_s == 1 && s[0] == 's'){
        cout << "YES\n";
        return ;
    }
    if(cnt_p == 1 && s[n - 1] == 'p'){
        cout << "YES\n";
        return ;
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