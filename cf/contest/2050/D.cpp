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
    string s; cin >> s;
    int n = s.size();
    if(n == 1){
        cout << s << "\n";
        return ;
    }

    vector<int> s_i(s.begin(), s.end());

    for(int i = 1; i < n; i++){
        for(int j = i; j >= max(1, i - 9); j--){
            if(s[j] - 1 > s[j - 1]){
                swap(s[j], s[j - 1]);
                s[j - 1] -= 1;
            }
        }
    }

    cout << s << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}