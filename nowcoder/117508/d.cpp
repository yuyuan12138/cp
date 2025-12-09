#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    const int n = s.size();
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans += 1ll * (i + 1) * (n - i);
        for (int j = i; j + i < n; j += i) {
            
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}