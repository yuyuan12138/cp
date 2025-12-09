/**
 *      author:  yuyuan567
 *      created: 2025-08-10 21:09:54
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
    int n, x;
    std::cin >> n >> x;
    std::string s;
    std::cin >> s;
    if (x == n || x == 1) {
        std::cout << "1\n";
    } else {
        x--;
        int box_before = -0x3f3f3f3f;
        for (int i = x - 1; i >= 0; i--) {
            if (s[i] == '#') {
                box_before = i;
                break;
            }
        }
        int box_after = 0x3f3f3f3f;
        for (int i = x + 1; i < n; i++) {
            if (s[i] == '#') {
                box_after = i;
                break;
            }
        }
        if (box_after == 0x3f3f3f3f && box_before == -0x3f3f3f3f) {
            std::cout << "1\n";
        } else {
            std::cout << std::max(std::min(x + 1, n - box_after + 1), std::min(n - x, box_before + 2)) << "\n";
        }
    }
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