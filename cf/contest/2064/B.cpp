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
    int n; cin >> n;
    vector<int> nums(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> nums[i];
    }
    if(n == 1){
        cout << "1 1\n";
        return ;
    }
    if(n == 2){
        if(nums[1] != nums[2]){
            cout << "1 2\n";
            return ;
        }else{
            cout << 0 << "\n";
            return ;
        }
    }
    vector<int> freq(n + 1);
    for(int i = 1; i <= n; i++){
        freq[nums[i]]++;
    }

    vector<int> length(n + 1);
    if(freq[nums[1]] == 1){
        length[1] = 1;
    }
    for(int i = 2; i <= n; i++){
        if(freq[nums[i]] == 1){
            length[i] = length[i - 1] + 1;
        }
    }
    int mx = *max_element(length.begin() + 1, length.end());
    if(mx == 0){
        cout << 0 << "\n";
    }else{
        for(int i = 1; i <= n; i++){
            if(length[i] == mx){
                cout << i - length[i] + 1 << " " << i << "\n";
                return ;
            }
        }
    }
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}