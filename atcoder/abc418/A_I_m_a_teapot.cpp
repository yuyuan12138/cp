/**
 *      author:  yuyuan567
 *      created: 2025-08-10 01:39:57
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
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    if (n < 3) {
        std::cout << "No\n";
    } else {
        if (s[n - 1] == 'a' && s[n - 2] == 'e' && s[n - 3] == 't') {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return ;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    solve();
    return 0;
}