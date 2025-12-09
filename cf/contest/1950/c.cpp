/**
 *      author:  yuyuan567
 *      created: 2025-08-07 16:10:26
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
    std::string s;
    std::cin >> s;
    int h = 0, m = 0;
    h = (s[0] - '0') * 10 + (s[1] - '0');
    m = (s[3] - '0') * 10 + (s[4] - '0');

    bool is_PM = (h >= 12 && h <= 23);
    if (h > 12) {
        h -= 12;
    } else if (h == 0 && !is_PM) {
        h = 12;
    }
    // if (h == 12) {

    // }
    if (h < 10) {
        std::cout << "0";
    }
    std::cout << h;
    std::cout << ":";

    if (m < 10) {
        std::cout << "0";
    }
    std::cout << m << " ";
    if (is_PM) {
        std::cout << "PM\n";
    } else {
        std::cout << "AM\n";
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