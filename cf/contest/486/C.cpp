/**
 *      author:  yuyuan567
 *      created: 2025-08-05 15:19:26
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
    int n, p;
    std::cin >> n >> p;
    p--;
    std::string s;
    std::cin >> s;
    int l = 0, r = n / 2 - 1;

    if (n / 2 <= p)
        p = n - 1 - p;

    while (l < n / 2 && s[l] == s[n - 1 - l])
        l++;
    while (r >= 0 && s[r] == s[n - 1 - r])
        r--;

    int ans = 0;

    for (int i = l; i <= r; i++) {
        int temp = std::abs(s[i] - s[n - 1 - i]);
        ans += std::min(temp, 26 - temp);
    }
    if (l < r)
        ans += std::min(std::abs(p - l), std::abs(r - p)) + r - l;
    else if (l == r)
        ans += std::abs(p - r);
    std::cout << ans << "\n";

    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}