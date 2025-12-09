/**
 *      author:  yuyuan567
 *      created: 2025-11-18 19:12:50
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using ll = long long;
using ull = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, a, b;
    std::string s;
    std::cin >> n >> a >> b >> s;
    ll ans = 0;
    auto dfs = [&](this auto&& self, int l, int r) -> void {
        if (l >= r) {
            return ;
        }        
        int mid = (l + r) >> 1;
        self(l, mid);
        self(mid, r);
        
    };
    return 0;
}