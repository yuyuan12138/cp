/**
 *      author:  yuyuan567
 *      created: 2025-08-10 23:30:06
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
    int n, k;
    std::cin >> n >> k;
    std::vector<int> s(n), t(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    std::map<int, int> freqs;
    for (int i = 0; i < n; i++) {
        int div = s[i] % k;
        freqs[div]++;
    }

    for (int i = 0; i < n; i++) {
        std::cin >> t[i];
    }
    for (int i = 0; i < n; i++) {
        int div1 = t[i] % k;
        int div2 = std::abs(div1 - k);
        if (freqs.find(div1) == freqs.end() && freqs.find(div2) == freqs.end()) {
            std::cout << "NO\n";
            return;
        }
        if (freqs[div1] == 0 && freqs[div2] == 0) {
            std::cout << "NO\n";
            return;
        }
        if (freqs[div1] != 0) {
            freqs[div1]--;
        } else {
            freqs[div2]--;
        }
    }
    std::cout << "YES\n";

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