#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::map<i64, int> cnt;
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        int val;
        std::cin >> val;
        for (auto& [x, pos] : cnt) {
            if (x * val > 2 * n) {
                break;
            }
            if (x * val == pos + i + 2) {
                ans++;
            }
        }
        cnt[val] = i;
    }
    std::cout << ans << '\n';
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