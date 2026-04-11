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
    int a, b; cin >> a >> b;
    if(a == b){
        cout << 1 << "\n";
        cout << a << "\n";
        return ;
    }
    cout << 3 << "\n";
    cout << b << " ";
    int tot = 3 * a;
    
    if(b > a){
        cout << b + 1 << " ";
        cout << tot - b - 1 - b << "\n";
    }else{
        cout << b - 1 << " ";
        cout << tot - b + 1 - b << "\n";
    }
    

    return ;
}

int main() {
    speedup();
    solve();
    return 0;
}
