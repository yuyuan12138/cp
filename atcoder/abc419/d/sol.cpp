/**
 *      author:  yuyuan567
 *      created: 2025-08-17 16:19:17
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::string s, t;
    std::cin >> s >> t;
    std::vector<int> diff(n + 1);
    while (m--) {
        int l, r;
        std::cin >> l >> r;
        l--, r--;
        diff[l] += 1;
        diff[r + 1] -= 1;
    }
    std::vector<int> pref(n + 1);
    pref[0] = diff[0];
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + diff[i + 1];
    }
    for (int i = 0; i < n; i++) {
        if (pref[i] % 2) {
            std::swap(s[i], t[i]);
        }
    }
    std::cout << s;
    return 0;
}
