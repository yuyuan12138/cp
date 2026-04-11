/**
 *      author:  yuyuan567
 *      created: 2025-08-07 15:59:49
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "../../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;

void solve(){
    int a, b, c;
    std::cin >> a >> b >> c;
    // std::vector<int> v = {a, b, c};
    // std::sort()
    if (a < b && b < c) {
        std::cout << "STAIR\n";
    } else if(a < b && b > c) {
        std::cout << "PEAK\n";
    } else {
        std::cout << "NONE\n";
    }
    return ;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1; std::cin >> t;
    while(t--) solve();
    return 0;
}