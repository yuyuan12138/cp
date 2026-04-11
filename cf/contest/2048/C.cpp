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
    cout << 1 << " " << n << " ";
    
    string matching;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            matching = s.substr(i, n - i);
            break;
        }
    }
    // cout << matching << "\n";
    int n2 = matching.size();
    vector<int> digits(n2);
    int best_left = 1, best_right = 1;
    for(int i = 0; i < n - n2; i++){
        for(int j = i; j < n2 + i; j++){
            if((s[j] == '1' && matching[j - i] == '0') || (s[j] == '0' && matching[j - i] == '1')){
                if(digits[j - i] != 1){
                    digits[j - i] = 1;
                    best_left = i + 1;
                    best_right = n2 + i;
                }
            }else{
                if(digits[j - i] == 1){
                    break;
                }
            }
        }
    }
    cout << best_left << " " << best_right << "\n";

    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}