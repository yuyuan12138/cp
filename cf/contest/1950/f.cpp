/**
 *      author:  yuyuan567
 *      created: 2025-08-07 17:10:38
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
    if (a + 1 != c) {
        std::cout << "-1\n";
    } else if(a + b + c == 1) {
        std::cout << "0\n";
    } else {
        int cur = 1, nxt = 0, res = 1;
        for (int i = 0; i < a + b; i++) {
            if (!cur) {
                std::swap(nxt, cur);
                res++;
            }
            cur--;
            nxt++;
            if (i < a) {
                nxt++;
            }
        }
        std::cout << res << "\n";
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