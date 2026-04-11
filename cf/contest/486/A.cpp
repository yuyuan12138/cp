/**
 *      author:  yuyuan567
 *      created: 2025-08-05 14:50:07
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

template <typename T>
T power_with_mod(T base, T exp, T mod) {
    if (exp == 0)
        return 1;
    if (exp == 1)
        return base;
    if (exp % 2) {
        return (power_with_mod(base, exp / 2, mod) % mod) * (power_with_mod(base, exp / 2, mod) % mod) % mod * base %
            mod;
    }
    return (power_with_mod(base, exp / 2, mod) % mod) * (power_with_mod(base, exp / 2, mod) % mod) % mod;
}

template <typename T>
T power(T base, T exp) {
    if (exp == 0)
        return 1;
    if (exp == 1)
        return base;
    if (exp % 2) {
        return power(base, exp / 2) * power(base, exp / 2) * base;
    }
    return power(base, exp / 2) * power(base, exp / 2);
}

void solve() {
    ll n;
    std::cin >> n;
    if (n % 2 == 0) {
        std::cout << n / 2 << "\n";
    } else {
        std::cout << (-1LL + -1LL * n) / 2 << "\n";
    }
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--)
        solve();
    return 0;
}