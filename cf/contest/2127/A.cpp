/**
 *      author:  yuyuan567
 *      created: 2025-08-10 20:51:00
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

void solve() {
    int n;
    std::cin >> n;
    std::set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        s.insert(x);
    }
    
    s.erase(-1);
    if (s.size() <= 1 && !s.count(0))
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}
