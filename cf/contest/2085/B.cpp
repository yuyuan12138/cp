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
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        cin >> nums[i];
        if(!nums[i]) cnt++;
    }
    if(cnt == 0){
        cout << "1\n";
        cout << "1 " << n << "\n";
        return ;
    }
    if(cnt == 1){
        if(nums[n] == 0){
            cout << 2 << "\n";
            cout << n - 1 << " " << n << "\n";
            cout << "1 " << n - 1 << "\n";
            return ;
        }
        cout << 2 << "\n";
        cout << "1 " << n - 1 << "\n";
        cout << "1 2\n";
        return ;
    }
    for(int i = 1; i <= n; i++){
        if(!nums[i]){
            cout << "3\n";
            cout << i + 1 << " " << n << "\n";
            cout << 1 << " " << i << "\n";
            cout << "1 2\n";
            return ;
        }
    }
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}