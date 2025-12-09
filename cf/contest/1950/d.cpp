/**
 *      author:  yuyuan567
 *      created: 2025-08-07 16:25:09
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

constexpr int MAX = 1e5 + 7;

std::vector<int> inits;

void init() {
    for (int i = 2; i <= MAX; i++) {
        int cur = i;
        bool ok = false;

        while (cur) {
            if (cur % 10 > 1) {
                ok = true;
                break;
            } else {
                cur /= 10;
            }
        }
        if (!ok) {
            inits.push_back(i);
        }
    }
}

void solve(){
    int n;
    std::cin >> n;
    if (n == 1) {
        std::cout << "YES\n";
    } else {
        bool ans = [&](this auto&& self, int x) -> bool {
            if (x == 1) {
                return true;
            } else {
                bool l = false;
                for (int i: inits) {
                    if (x % i == 0) {
                        l |= self(x / i);
                    }
                }
                return l;
            }
            
        }(n);
        if (ans) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return ;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    init();
    int t = 1; std::cin >> t;
    while(t--) solve();
    return 0;
}